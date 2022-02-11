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
static void F_27 ( struct V_18 * V_19 , const struct V_36 * V_37 , void * V_25 ,
int V_38 , T_4 * V_39 , int V_40 )
{
struct V_41 * V_42 = F_28 ( V_19 ) ;
if ( V_19 -> V_43 != V_44 ) {
if ( ! ( V_42 -> V_45 & V_46 ) &&
( ! V_19 -> V_47 || V_19 -> V_47 -> V_48 & V_49 ) ) {
V_19 -> V_43 = V_44 ;
V_19 -> V_50 = F_29 ( V_19 ) +
F_30 ( V_19 ) +
V_37 -> V_51 * 4 ;
V_19 -> V_52 = ( void * ) V_39 - V_25 ;
* V_39 = ~ F_31 ( V_37 -> V_53 , V_37 -> V_54 ,
V_38 , V_37 -> V_55 , 0 ) ;
} else {
* V_39 = 0 ;
* V_39 = F_31 ( V_37 -> V_53 , V_37 -> V_54 ,
V_38 , V_37 -> V_55 ,
F_32 ( V_25 , V_38 ,
0 ) ) ;
if ( V_37 -> V_55 == V_56 && ! * V_39 )
* V_39 = V_57 ;
}
} else
F_33 ( V_39 , V_19 ,
F_18 ( V_40 ) , F_18 ( V_38 ) , 1 ) ;
}
int F_34 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
enum V_5 V_6 ,
unsigned int V_21 ,
unsigned int V_22 ,
const char * V_23 ,
unsigned int V_24 , bool V_58 )
{
struct V_36 * V_37 ;
struct V_59 * V_60 ;
int V_40 , V_38 ;
if ( ! F_35 ( V_19 , V_19 -> V_28 ) )
return 0 ;
if ( V_24 > V_22 &&
V_24 - V_22 > F_22 ( V_19 ) &&
! F_20 ( V_19 , V_24 - V_22 ) )
return 0 ;
F_36 ( V_19 ) ;
V_37 = F_17 ( V_19 ) ;
V_60 = ( void * ) V_37 + V_37 -> V_51 * 4 ;
V_40 = V_19 -> V_28 - V_37 -> V_51 * 4 ;
F_11 ( V_19 , V_37 -> V_51 * 4 + V_60 -> V_61 * 4 ,
V_21 , V_22 , V_23 , V_24 ) ;
V_38 = V_19 -> V_28 - V_37 -> V_51 * 4 ;
F_27 ( V_19 , V_37 , V_60 , V_38 , & V_60 -> V_39 , V_40 ) ;
if ( V_58 && V_24 != V_22 )
F_23 ( V_4 , V_6 , V_60 -> V_1 ,
( int ) V_24 - ( int ) V_22 ) ;
return 1 ;
}
int
F_37 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
enum V_5 V_6 ,
unsigned int V_21 ,
unsigned int V_22 ,
const char * V_23 ,
unsigned int V_24 )
{
struct V_36 * V_37 ;
struct V_62 * V_63 ;
int V_38 , V_40 ;
V_37 = F_17 ( V_19 ) ;
if ( V_19 -> V_28 < V_37 -> V_51 * 4 + sizeof( * V_63 ) +
V_21 + V_22 )
return 0 ;
if ( ! F_35 ( V_19 , V_19 -> V_28 ) )
return 0 ;
if ( V_24 > V_22 &&
V_24 - V_22 > F_22 ( V_19 ) &&
! F_20 ( V_19 , V_24 - V_22 ) )
return 0 ;
V_37 = F_17 ( V_19 ) ;
V_63 = ( void * ) V_37 + V_37 -> V_51 * 4 ;
V_40 = V_19 -> V_28 - V_37 -> V_51 * 4 ;
F_11 ( V_19 , V_37 -> V_51 * 4 + sizeof( * V_63 ) ,
V_21 , V_22 , V_23 , V_24 ) ;
V_38 = V_19 -> V_28 - V_37 -> V_51 * 4 ;
V_63 -> V_28 = F_18 ( V_38 ) ;
if ( ! V_63 -> V_39 && V_19 -> V_43 != V_44 )
return 1 ;
F_27 ( V_19 , V_37 , V_63 , V_38 , & V_63 -> V_39 , V_40 ) ;
return 1 ;
}
static void
F_38 ( struct V_18 * V_19 ,
struct V_59 * V_60 ,
unsigned int V_64 ,
unsigned int V_65 ,
struct V_11 * V_66 )
{
while ( V_64 < V_65 ) {
struct V_67 * V_68 ;
T_3 V_69 , V_70 ;
V_68 = ( void * ) V_19 -> V_25 + V_64 ;
if ( F_10 ( F_25 ( V_68 -> V_71 ) - V_66 -> V_14 ,
V_66 -> V_16 ) )
V_69 = F_39 ( F_25 ( V_68 -> V_71 )
- V_66 -> V_15 ) ;
else
V_69 = F_39 ( F_25 ( V_68 -> V_71 )
- V_66 -> V_14 ) ;
if ( F_10 ( F_25 ( V_68 -> V_72 ) - V_66 -> V_14 ,
V_66 -> V_16 ) )
V_70 = F_39 ( F_25 ( V_68 -> V_72 )
- V_66 -> V_15 ) ;
else
V_70 = F_39 ( F_25 ( V_68 -> V_72 )
- V_66 -> V_14 ) ;
F_4 ( L_7 ,
F_25 ( V_68 -> V_71 ) , V_69 ,
F_25 ( V_68 -> V_72 ) , V_70 ) ;
F_40 ( & V_60 -> V_39 , V_19 ,
V_68 -> V_71 , V_69 , 0 ) ;
F_40 ( & V_60 -> V_39 , V_19 ,
V_68 -> V_72 , V_70 , 0 ) ;
V_68 -> V_71 = V_69 ;
V_68 -> V_72 = V_70 ;
V_64 += sizeof( * V_68 ) ;
}
}
static inline unsigned int
F_41 ( struct V_18 * V_19 ,
struct V_59 * V_60 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
unsigned int V_8 , V_73 , V_74 ;
struct V_9 * V_10 = F_3 ( V_4 ) ;
V_73 = F_42 ( V_19 ) + sizeof( struct V_59 ) ;
V_74 = F_42 ( V_19 ) + V_60 -> V_61 * 4 ;
if ( ! F_35 ( V_19 , V_74 ) )
return 0 ;
V_8 = F_2 ( V_6 ) ;
while ( V_73 < V_74 ) {
unsigned char * V_75 = V_19 -> V_25 + V_73 ;
switch ( V_75 [ 0 ] ) {
case V_76 :
return 1 ;
case V_77 :
V_73 ++ ;
continue;
default:
if ( V_73 + 1 == V_74 ||
V_73 + V_75 [ 1 ] > V_74 ||
V_75 [ 1 ] < 2 )
return 0 ;
if ( V_75 [ 0 ] == V_78 &&
V_75 [ 1 ] >= 2 + V_79 &&
( ( V_75 [ 1 ] - 2 ) % V_79 ) == 0 )
F_38 ( V_19 , V_60 , V_73 + 2 ,
V_73 + V_75 [ 1 ] , & V_10 -> V_1 [ ! V_8 ] ) ;
V_73 += V_75 [ 1 ] ;
}
}
return 1 ;
}
int
F_43 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
struct V_59 * V_60 ;
int V_8 ;
T_3 V_80 , V_81 ;
T_2 V_82 , V_83 ;
struct V_9 * V_10 = F_3 ( V_4 ) ;
struct V_11 * V_12 , * V_84 ;
V_8 = F_2 ( V_6 ) ;
V_12 = & V_10 -> V_1 [ V_8 ] ;
V_84 = & V_10 -> V_1 [ ! V_8 ] ;
if ( ! F_35 ( V_19 , F_42 ( V_19 ) + sizeof( * V_60 ) ) )
return 0 ;
V_60 = ( void * ) V_19 -> V_25 + F_42 ( V_19 ) ;
if ( F_10 ( F_25 ( V_60 -> V_1 ) , V_12 -> V_16 ) )
V_82 = V_12 -> V_15 ;
else
V_82 = V_12 -> V_14 ;
if ( F_10 ( F_25 ( V_60 -> V_85 ) - V_84 -> V_14 ,
V_84 -> V_16 ) )
V_83 = V_84 -> V_15 ;
else
V_83 = V_84 -> V_14 ;
V_80 = F_39 ( F_25 ( V_60 -> V_1 ) + V_82 ) ;
V_81 = F_39 ( F_25 ( V_60 -> V_85 ) - V_83 ) ;
F_40 ( & V_60 -> V_39 , V_19 , V_60 -> V_1 , V_80 , 0 ) ;
F_40 ( & V_60 -> V_39 , V_19 , V_60 -> V_85 , V_81 , 0 ) ;
F_4 ( L_8 ,
F_25 ( V_60 -> V_1 ) , F_25 ( V_80 ) , F_25 ( V_60 -> V_85 ) ,
F_25 ( V_81 ) ) ;
V_60 -> V_1 = V_80 ;
V_60 -> V_85 = V_81 ;
return F_41 ( V_19 , V_60 , V_4 , V_6 ) ;
}
void F_44 ( struct V_3 * V_4 ,
struct V_86 * exp )
{
struct V_87 V_88 ;
F_12 ( V_4 -> V_34 & V_89 ) ;
V_88 . V_90 = V_91 ;
V_88 . V_92 = V_88 . V_93
= V_4 -> V_94 -> V_95 [ ! exp -> V_8 ] . V_96 . V_97 . V_98 . V_99 ;
F_45 ( V_4 , & V_88 , V_100 ) ;
V_88 . V_90 = ( V_91 | V_101 ) ;
V_88 . V_102 = V_88 . V_103 = exp -> V_104 ;
V_88 . V_92 = V_88 . V_93
= V_4 -> V_94 -> V_95 [ ! exp -> V_8 ] . V_96 . V_105 . V_98 . V_99 ;
F_45 ( V_4 , & V_88 , V_106 ) ;
}
