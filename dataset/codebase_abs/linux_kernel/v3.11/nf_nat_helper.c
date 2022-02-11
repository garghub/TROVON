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
F_15 ( V_19 ) - ( F_14 ( V_19 ) + V_20 +
V_21 + V_22 ) ) ;
memcpy ( V_25 + V_21 , V_23 , V_24 ) ;
if ( V_24 > V_22 ) {
F_4 ( L_4
L_5 , V_24 - V_22 , V_19 -> V_26 ) ;
F_16 ( V_19 , V_24 - V_22 ) ;
} else {
F_4 ( L_6
L_5 , V_22 - V_24 , V_19 -> V_26 ) ;
F_17 ( V_19 , V_19 -> V_26 + V_24 - V_22 ) ;
}
if ( F_18 ( (struct V_3 * ) V_19 -> V_27 ) == V_28 ) {
F_19 ( V_19 ) -> V_29 = F_20 ( V_19 -> V_26 ) ;
F_21 ( F_19 ( V_19 ) ) ;
} else
F_22 ( V_19 ) -> V_30 =
F_20 ( V_19 -> V_26 - sizeof( struct V_31 ) ) ;
}
static int F_23 ( struct V_18 * V_19 , unsigned int V_32 )
{
if ( V_19 -> V_26 + V_32 > 65535 )
return 0 ;
if ( F_24 ( V_19 , 0 , V_32 - F_25 ( V_19 ) , V_33 ) )
return 0 ;
return 1 ;
}
void F_26 ( struct V_3 * V_4 , enum V_5 V_6 ,
T_3 V_1 , T_2 V_34 )
{
if ( ! V_34 )
return;
F_27 ( V_35 , & V_4 -> V_36 ) ;
F_1 ( F_28 ( V_1 ) , V_34 , V_4 , V_6 ) ;
F_29 ( V_37 , V_4 ) ;
}
void F_30 ( struct V_18 * V_19 , struct V_3 * V_4 ,
T_1 V_6 , int V_34 )
{
const struct V_38 * V_39 ;
if ( F_31 ( V_4 ) != V_40 )
return;
V_39 = (struct V_38 * ) ( F_14 ( V_19 ) + F_32 ( V_19 ) ) ;
F_26 ( V_4 , V_6 , V_39 -> V_1 , V_34 ) ;
}
int F_33 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
enum V_5 V_6 ,
unsigned int V_41 ,
unsigned int V_21 ,
unsigned int V_22 ,
const char * V_23 ,
unsigned int V_24 , bool V_42 )
{
const struct V_43 * V_44 ;
struct V_38 * V_45 ;
int V_46 , V_47 ;
if ( ! F_34 ( V_19 , V_19 -> V_26 ) )
return 0 ;
if ( V_24 > V_22 &&
V_24 - V_22 > F_25 ( V_19 ) &&
! F_23 ( V_19 , V_24 - V_22 ) )
return 0 ;
F_35 ( V_19 ) ;
V_45 = ( void * ) V_19 -> V_25 + V_41 ;
V_46 = V_19 -> V_26 - V_41 ;
F_11 ( V_19 , V_41 + V_45 -> V_48 * 4 ,
V_21 , V_22 , V_23 , V_24 ) ;
V_47 = V_19 -> V_26 - V_41 ;
V_44 = F_36 ( F_18 ( V_4 ) ) ;
V_44 -> V_49 ( V_19 , V_40 , V_45 , & V_45 -> V_50 ,
V_47 , V_46 ) ;
if ( V_42 && V_24 != V_22 )
F_26 ( V_4 , V_6 , V_45 -> V_1 ,
( int ) V_24 - ( int ) V_22 ) ;
return 1 ;
}
int
F_37 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
enum V_5 V_6 ,
unsigned int V_41 ,
unsigned int V_21 ,
unsigned int V_22 ,
const char * V_23 ,
unsigned int V_24 )
{
const struct V_43 * V_44 ;
struct V_51 * V_52 ;
int V_47 , V_46 ;
if ( ! F_34 ( V_19 , V_19 -> V_26 ) )
return 0 ;
if ( V_24 > V_22 &&
V_24 - V_22 > F_25 ( V_19 ) &&
! F_23 ( V_19 , V_24 - V_22 ) )
return 0 ;
V_52 = ( void * ) V_19 -> V_25 + V_41 ;
V_46 = V_19 -> V_26 - V_41 ;
F_11 ( V_19 , V_41 + sizeof( * V_52 ) ,
V_21 , V_22 , V_23 , V_24 ) ;
V_47 = V_19 -> V_26 - V_41 ;
V_52 -> V_26 = F_20 ( V_47 ) ;
if ( ! V_52 -> V_50 && V_19 -> V_53 != V_54 )
return 1 ;
V_44 = F_36 ( F_18 ( V_4 ) ) ;
V_44 -> V_49 ( V_19 , V_55 , V_52 , & V_52 -> V_50 ,
V_47 , V_46 ) ;
return 1 ;
}
static void
F_38 ( struct V_18 * V_19 ,
struct V_38 * V_45 ,
unsigned int V_56 ,
unsigned int V_57 ,
struct V_11 * V_58 )
{
while ( V_56 < V_57 ) {
struct V_59 * V_60 ;
T_3 V_61 , V_62 ;
V_60 = ( void * ) V_19 -> V_25 + V_56 ;
if ( F_10 ( F_28 ( V_60 -> V_63 ) - V_58 -> V_14 ,
V_58 -> V_16 ) )
V_61 = F_39 ( F_28 ( V_60 -> V_63 )
- V_58 -> V_15 ) ;
else
V_61 = F_39 ( F_28 ( V_60 -> V_63 )
- V_58 -> V_14 ) ;
if ( F_10 ( F_28 ( V_60 -> V_64 ) - V_58 -> V_14 ,
V_58 -> V_16 ) )
V_62 = F_39 ( F_28 ( V_60 -> V_64 )
- V_58 -> V_15 ) ;
else
V_62 = F_39 ( F_28 ( V_60 -> V_64 )
- V_58 -> V_14 ) ;
F_4 ( L_7 ,
F_28 ( V_60 -> V_63 ) , V_61 ,
F_28 ( V_60 -> V_64 ) , V_62 ) ;
F_40 ( & V_45 -> V_50 , V_19 ,
V_60 -> V_63 , V_61 , 0 ) ;
F_40 ( & V_45 -> V_50 , V_19 ,
V_60 -> V_64 , V_62 , 0 ) ;
V_60 -> V_63 = V_61 ;
V_60 -> V_64 = V_62 ;
V_56 += sizeof( * V_60 ) ;
}
}
static inline unsigned int
F_41 ( struct V_18 * V_19 ,
unsigned int V_41 ,
struct V_38 * V_45 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
unsigned int V_8 , V_65 , V_66 ;
struct V_9 * V_10 = F_3 ( V_4 ) ;
V_65 = V_41 + sizeof( struct V_38 ) ;
V_66 = V_41 + V_45 -> V_48 * 4 ;
if ( ! F_34 ( V_19 , V_66 ) )
return 0 ;
V_8 = F_2 ( V_6 ) ;
while ( V_65 < V_66 ) {
unsigned char * V_67 = V_19 -> V_25 + V_65 ;
switch ( V_67 [ 0 ] ) {
case V_68 :
return 1 ;
case V_69 :
V_65 ++ ;
continue;
default:
if ( V_65 + 1 == V_66 ||
V_65 + V_67 [ 1 ] > V_66 ||
V_67 [ 1 ] < 2 )
return 0 ;
if ( V_67 [ 0 ] == V_70 &&
V_67 [ 1 ] >= 2 + V_71 &&
( ( V_67 [ 1 ] - 2 ) % V_71 ) == 0 )
F_38 ( V_19 , V_45 , V_65 + 2 ,
V_65 + V_67 [ 1 ] , & V_10 -> V_1 [ ! V_8 ] ) ;
V_65 += V_67 [ 1 ] ;
}
}
return 1 ;
}
int
F_42 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
enum V_5 V_6 ,
unsigned int V_41 )
{
struct V_38 * V_45 ;
int V_8 ;
T_3 V_72 , V_73 ;
T_2 V_74 , V_75 ;
struct V_9 * V_10 = F_3 ( V_4 ) ;
struct V_11 * V_12 , * V_76 ;
V_8 = F_2 ( V_6 ) ;
V_12 = & V_10 -> V_1 [ V_8 ] ;
V_76 = & V_10 -> V_1 [ ! V_8 ] ;
if ( ! F_34 ( V_19 , V_41 + sizeof( * V_45 ) ) )
return 0 ;
V_45 = ( void * ) V_19 -> V_25 + V_41 ;
if ( F_10 ( F_28 ( V_45 -> V_1 ) , V_12 -> V_16 ) )
V_74 = V_12 -> V_15 ;
else
V_74 = V_12 -> V_14 ;
if ( F_10 ( F_28 ( V_45 -> V_77 ) - V_76 -> V_14 ,
V_76 -> V_16 ) )
V_75 = V_76 -> V_15 ;
else
V_75 = V_76 -> V_14 ;
V_72 = F_39 ( F_28 ( V_45 -> V_1 ) + V_74 ) ;
V_73 = F_39 ( F_28 ( V_45 -> V_77 ) - V_75 ) ;
F_40 ( & V_45 -> V_50 , V_19 , V_45 -> V_1 , V_72 , 0 ) ;
F_40 ( & V_45 -> V_50 , V_19 , V_45 -> V_77 , V_73 , 0 ) ;
F_4 ( L_8 ,
F_28 ( V_45 -> V_1 ) , F_28 ( V_72 ) , F_28 ( V_45 -> V_77 ) ,
F_28 ( V_73 ) ) ;
V_45 -> V_1 = V_72 ;
V_45 -> V_77 = V_73 ;
return F_41 ( V_19 , V_41 , V_45 , V_4 , V_6 ) ;
}
void F_43 ( struct V_3 * V_4 ,
struct V_78 * exp )
{
struct V_79 V_80 ;
F_12 ( V_4 -> V_36 & V_81 ) ;
V_80 . V_82 = V_83 ;
V_80 . V_84 = V_80 . V_85
= V_4 -> V_86 -> V_87 [ ! exp -> V_8 ] . V_88 . V_89 . V_90 ;
F_44 ( V_4 , & V_80 , V_91 ) ;
V_80 . V_82 = ( V_83 | V_92 ) ;
V_80 . V_93 = V_80 . V_94 = exp -> V_95 ;
V_80 . V_84 = V_80 . V_85
= V_4 -> V_86 -> V_87 [ ! exp -> V_8 ] . V_88 . V_96 . V_90 ;
F_44 ( V_4 , & V_80 , V_97 ) ;
}
