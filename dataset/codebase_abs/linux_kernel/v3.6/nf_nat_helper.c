static inline void
F_1 ( T_1 V_1 ,
int V_2 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
enum V_7 V_8 = F_2 ( V_6 ) ;
struct V_9 * V_10 = F_3 ( V_4 ) ;
struct V_11 * V_12 = & V_10 -> V_1 [ V_8 ] ;
F_4 ( L_1 ,
V_1 , V_2 ) ;
F_4 ( L_2 ) ;
F_5 ( V_12 ) ;
F_6 ( & V_13 ) ;
if ( V_12 -> V_14 == V_12 -> V_15 ||
F_7 ( V_12 -> V_16 , V_1 ) ) {
V_12 -> V_16 = V_1 ;
V_12 -> V_14 = V_12 -> V_15 ;
V_12 -> V_15 += V_2 ;
}
F_8 ( & V_13 ) ;
F_4 ( L_3 ) ;
F_5 ( V_12 ) ;
}
T_2 F_9 ( const struct V_3 * V_4 ,
enum V_7 V_8 ,
T_1 V_1 )
{
struct V_9 * V_10 = F_3 ( V_4 ) ;
struct V_11 * V_12 ;
T_2 V_17 ;
if ( ! V_10 )
return 0 ;
V_12 = & V_10 -> V_1 [ V_8 ] ;
F_6 ( & V_13 ) ;
V_17 = F_10 ( V_1 , V_12 -> V_16 )
? V_12 -> V_15 : V_12 -> V_14 ;
F_8 ( & V_13 ) ;
return V_17 ;
}
static void F_11 ( struct V_18 * V_19 ,
unsigned int V_20 ,
unsigned int V_21 ,
unsigned int V_22 ,
const char * V_23 ,
unsigned int V_24 )
{
unsigned char * V_25 ;
F_12 ( F_13 ( V_19 ) ) ;
V_25 = F_14 ( V_19 ) + V_20 ;
memmove ( V_25 + V_21 + V_24 ,
V_25 + V_21 + V_22 ,
V_19 -> V_26 - ( V_19 -> V_27 + V_20 +
V_21 + V_22 ) ) ;
memcpy ( V_25 + V_21 , V_23 , V_24 ) ;
if ( V_24 > V_22 ) {
F_4 ( L_4
L_5 , V_24 - V_22 , V_19 -> V_28 ) ;
F_15 ( V_19 , V_24 - V_22 ) ;
} else {
F_4 ( L_6
L_5 , V_22 - V_24 , V_19 -> V_28 ) ;
F_16 ( V_19 , V_19 -> V_28 + V_24 - V_22 ) ;
}
F_17 ( V_19 ) -> V_29 = F_18 ( V_19 -> V_28 ) ;
F_19 ( F_17 ( V_19 ) ) ;
}
static int F_20 ( struct V_18 * V_19 , unsigned int V_30 )
{
if ( V_19 -> V_28 + V_30 > 65535 )
return 0 ;
if ( F_21 ( V_19 , 0 , V_30 - F_22 ( V_19 ) , V_31 ) )
return 0 ;
return 1 ;
}
void F_23 ( struct V_3 * V_4 , enum V_5 V_6 ,
T_3 V_1 , T_2 V_32 )
{
if ( ! V_32 )
return;
F_24 ( V_33 , & V_4 -> V_34 ) ;
F_1 ( F_25 ( V_1 ) , V_32 , V_4 , V_6 ) ;
F_26 ( V_35 , V_4 ) ;
}
void F_27 ( struct V_18 * V_19 , struct V_3 * V_4 ,
T_1 V_6 , int V_32 )
{
const struct V_36 * V_37 ;
if ( F_28 ( V_4 ) != V_38 )
return;
V_37 = (struct V_36 * ) ( F_14 ( V_19 ) + F_29 ( V_19 ) ) ;
F_23 ( V_4 , V_6 , V_37 -> V_1 , V_32 ) ;
}
static void F_30 ( struct V_18 * V_19 , const struct V_39 * V_40 , void * V_25 ,
int V_41 , T_4 * V_42 , int V_43 )
{
struct V_44 * V_45 = F_31 ( V_19 ) ;
if ( V_19 -> V_46 != V_47 ) {
if ( ! ( V_45 -> V_48 & V_49 ) &&
( ! V_19 -> V_50 || V_19 -> V_50 -> V_51 & V_52 ) ) {
V_19 -> V_46 = V_47 ;
V_19 -> V_53 = F_32 ( V_19 ) +
F_33 ( V_19 ) +
V_40 -> V_54 * 4 ;
V_19 -> V_55 = ( void * ) V_42 - V_25 ;
* V_42 = ~ F_34 ( V_40 -> V_56 , V_40 -> V_57 ,
V_41 , V_40 -> V_58 , 0 ) ;
} else {
* V_42 = 0 ;
* V_42 = F_34 ( V_40 -> V_56 , V_40 -> V_57 ,
V_41 , V_40 -> V_58 ,
F_35 ( V_25 , V_41 ,
0 ) ) ;
if ( V_40 -> V_58 == V_59 && ! * V_42 )
* V_42 = V_60 ;
}
} else
F_36 ( V_42 , V_19 ,
F_18 ( V_43 ) , F_18 ( V_41 ) , 1 ) ;
}
int F_37 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
enum V_5 V_6 ,
unsigned int V_21 ,
unsigned int V_22 ,
const char * V_23 ,
unsigned int V_24 , bool V_61 )
{
struct V_39 * V_40 ;
struct V_36 * V_62 ;
int V_43 , V_41 ;
if ( ! F_38 ( V_19 , V_19 -> V_28 ) )
return 0 ;
if ( V_24 > V_22 &&
V_24 - V_22 > F_22 ( V_19 ) &&
! F_20 ( V_19 , V_24 - V_22 ) )
return 0 ;
F_39 ( V_19 ) ;
V_40 = F_17 ( V_19 ) ;
V_62 = ( void * ) V_40 + V_40 -> V_54 * 4 ;
V_43 = V_19 -> V_28 - V_40 -> V_54 * 4 ;
F_11 ( V_19 , V_40 -> V_54 * 4 + V_62 -> V_63 * 4 ,
V_21 , V_22 , V_23 , V_24 ) ;
V_41 = V_19 -> V_28 - V_40 -> V_54 * 4 ;
F_30 ( V_19 , V_40 , V_62 , V_41 , & V_62 -> V_42 , V_43 ) ;
if ( V_61 && V_24 != V_22 )
F_23 ( V_4 , V_6 , V_62 -> V_1 ,
( int ) V_24 - ( int ) V_22 ) ;
return 1 ;
}
int
F_40 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
enum V_5 V_6 ,
unsigned int V_21 ,
unsigned int V_22 ,
const char * V_23 ,
unsigned int V_24 )
{
struct V_39 * V_40 ;
struct V_64 * V_65 ;
int V_41 , V_43 ;
if ( ! F_38 ( V_19 , V_19 -> V_28 ) )
return 0 ;
if ( V_24 > V_22 &&
V_24 - V_22 > F_22 ( V_19 ) &&
! F_20 ( V_19 , V_24 - V_22 ) )
return 0 ;
V_40 = F_17 ( V_19 ) ;
V_65 = ( void * ) V_40 + V_40 -> V_54 * 4 ;
V_43 = V_19 -> V_28 - V_40 -> V_54 * 4 ;
F_11 ( V_19 , V_40 -> V_54 * 4 + sizeof( * V_65 ) ,
V_21 , V_22 , V_23 , V_24 ) ;
V_41 = V_19 -> V_28 - V_40 -> V_54 * 4 ;
V_65 -> V_28 = F_18 ( V_41 ) ;
if ( ! V_65 -> V_42 && V_19 -> V_46 != V_47 )
return 1 ;
F_30 ( V_19 , V_40 , V_65 , V_41 , & V_65 -> V_42 , V_43 ) ;
return 1 ;
}
static void
F_41 ( struct V_18 * V_19 ,
struct V_36 * V_62 ,
unsigned int V_66 ,
unsigned int V_67 ,
struct V_11 * V_68 )
{
while ( V_66 < V_67 ) {
struct V_69 * V_70 ;
T_3 V_71 , V_72 ;
V_70 = ( void * ) V_19 -> V_25 + V_66 ;
if ( F_10 ( F_25 ( V_70 -> V_73 ) - V_68 -> V_14 ,
V_68 -> V_16 ) )
V_71 = F_42 ( F_25 ( V_70 -> V_73 )
- V_68 -> V_15 ) ;
else
V_71 = F_42 ( F_25 ( V_70 -> V_73 )
- V_68 -> V_14 ) ;
if ( F_10 ( F_25 ( V_70 -> V_74 ) - V_68 -> V_14 ,
V_68 -> V_16 ) )
V_72 = F_42 ( F_25 ( V_70 -> V_74 )
- V_68 -> V_15 ) ;
else
V_72 = F_42 ( F_25 ( V_70 -> V_74 )
- V_68 -> V_14 ) ;
F_4 ( L_7 ,
F_25 ( V_70 -> V_73 ) , V_71 ,
F_25 ( V_70 -> V_74 ) , V_72 ) ;
F_43 ( & V_62 -> V_42 , V_19 ,
V_70 -> V_73 , V_71 , 0 ) ;
F_43 ( & V_62 -> V_42 , V_19 ,
V_70 -> V_74 , V_72 , 0 ) ;
V_70 -> V_73 = V_71 ;
V_70 -> V_74 = V_72 ;
V_66 += sizeof( * V_70 ) ;
}
}
static inline unsigned int
F_44 ( struct V_18 * V_19 ,
struct V_36 * V_62 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
unsigned int V_8 , V_75 , V_76 ;
struct V_9 * V_10 = F_3 ( V_4 ) ;
V_75 = F_29 ( V_19 ) + sizeof( struct V_36 ) ;
V_76 = F_29 ( V_19 ) + V_62 -> V_63 * 4 ;
if ( ! F_38 ( V_19 , V_76 ) )
return 0 ;
V_8 = F_2 ( V_6 ) ;
while ( V_75 < V_76 ) {
unsigned char * V_77 = V_19 -> V_25 + V_75 ;
switch ( V_77 [ 0 ] ) {
case V_78 :
return 1 ;
case V_79 :
V_75 ++ ;
continue;
default:
if ( V_75 + 1 == V_76 ||
V_75 + V_77 [ 1 ] > V_76 ||
V_77 [ 1 ] < 2 )
return 0 ;
if ( V_77 [ 0 ] == V_80 &&
V_77 [ 1 ] >= 2 + V_81 &&
( ( V_77 [ 1 ] - 2 ) % V_81 ) == 0 )
F_41 ( V_19 , V_62 , V_75 + 2 ,
V_75 + V_77 [ 1 ] , & V_10 -> V_1 [ ! V_8 ] ) ;
V_75 += V_77 [ 1 ] ;
}
}
return 1 ;
}
int
F_45 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_36 * V_62 ;
int V_8 ;
T_3 V_82 , V_83 ;
T_2 V_84 , V_85 ;
struct V_9 * V_10 = F_3 ( V_4 ) ;
struct V_11 * V_12 , * V_86 ;
V_8 = F_2 ( V_6 ) ;
V_12 = & V_10 -> V_1 [ V_8 ] ;
V_86 = & V_10 -> V_1 [ ! V_8 ] ;
if ( ! F_38 ( V_19 , F_29 ( V_19 ) + sizeof( * V_62 ) ) )
return 0 ;
V_62 = ( void * ) V_19 -> V_25 + F_29 ( V_19 ) ;
if ( F_10 ( F_25 ( V_62 -> V_1 ) , V_12 -> V_16 ) )
V_84 = V_12 -> V_15 ;
else
V_84 = V_12 -> V_14 ;
if ( F_10 ( F_25 ( V_62 -> V_87 ) - V_86 -> V_14 ,
V_86 -> V_16 ) )
V_85 = V_86 -> V_15 ;
else
V_85 = V_86 -> V_14 ;
V_82 = F_42 ( F_25 ( V_62 -> V_1 ) + V_84 ) ;
V_83 = F_42 ( F_25 ( V_62 -> V_87 ) - V_85 ) ;
F_43 ( & V_62 -> V_42 , V_19 , V_62 -> V_1 , V_82 , 0 ) ;
F_43 ( & V_62 -> V_42 , V_19 , V_62 -> V_87 , V_83 , 0 ) ;
F_4 ( L_8 ,
F_25 ( V_62 -> V_1 ) , F_25 ( V_82 ) , F_25 ( V_62 -> V_87 ) ,
F_25 ( V_83 ) ) ;
V_62 -> V_1 = V_82 ;
V_62 -> V_87 = V_83 ;
return F_44 ( V_19 , V_62 , V_4 , V_6 ) ;
}
void F_46 ( struct V_3 * V_4 ,
struct V_88 * exp )
{
struct V_89 V_90 ;
F_12 ( V_4 -> V_34 & V_91 ) ;
V_90 . V_92 = V_93 ;
V_90 . V_94 = V_90 . V_95
= V_4 -> V_96 -> V_97 [ ! exp -> V_8 ] . V_98 . V_99 . V_100 . V_101 ;
F_47 ( V_4 , & V_90 , V_102 ) ;
V_90 . V_92 = ( V_93 | V_103 ) ;
V_90 . V_104 = V_90 . V_105 = exp -> V_106 ;
V_90 . V_94 = V_90 . V_95
= V_4 -> V_96 -> V_97 [ ! exp -> V_8 ] . V_98 . V_107 . V_100 . V_101 ;
F_47 ( V_4 , & V_90 , V_108 ) ;
}
