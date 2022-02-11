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
if ( F_17 ( (struct V_3 * ) V_19 -> V_29 ) == V_30 ) {
F_18 ( V_19 ) -> V_31 = F_19 ( V_19 -> V_28 ) ;
F_20 ( F_18 ( V_19 ) ) ;
} else
F_21 ( V_19 ) -> V_32 =
F_19 ( V_19 -> V_28 - sizeof( struct V_33 ) ) ;
}
static int F_22 ( struct V_18 * V_19 , unsigned int V_34 )
{
if ( V_19 -> V_28 + V_34 > 65535 )
return 0 ;
if ( F_23 ( V_19 , 0 , V_34 - F_24 ( V_19 ) , V_35 ) )
return 0 ;
return 1 ;
}
void F_25 ( struct V_3 * V_4 , enum V_5 V_6 ,
T_3 V_1 , T_2 V_36 )
{
if ( ! V_36 )
return;
F_26 ( V_37 , & V_4 -> V_38 ) ;
F_1 ( F_27 ( V_1 ) , V_36 , V_4 , V_6 ) ;
F_28 ( V_39 , V_4 ) ;
}
void F_29 ( struct V_18 * V_19 , struct V_3 * V_4 ,
T_1 V_6 , int V_36 )
{
const struct V_40 * V_41 ;
if ( F_30 ( V_4 ) != V_42 )
return;
V_41 = (struct V_40 * ) ( F_14 ( V_19 ) + F_31 ( V_19 ) ) ;
F_25 ( V_4 , V_6 , V_41 -> V_1 , V_36 ) ;
}
int F_32 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
enum V_5 V_6 ,
unsigned int V_43 ,
unsigned int V_21 ,
unsigned int V_22 ,
const char * V_23 ,
unsigned int V_24 , bool V_44 )
{
const struct V_45 * V_46 ;
struct V_40 * V_47 ;
int V_48 , V_49 ;
if ( ! F_33 ( V_19 , V_19 -> V_28 ) )
return 0 ;
if ( V_24 > V_22 &&
V_24 - V_22 > F_24 ( V_19 ) &&
! F_22 ( V_19 , V_24 - V_22 ) )
return 0 ;
F_34 ( V_19 ) ;
V_47 = ( void * ) V_19 -> V_25 + V_43 ;
V_48 = V_19 -> V_28 - V_43 ;
F_11 ( V_19 , V_43 + V_47 -> V_50 * 4 ,
V_21 , V_22 , V_23 , V_24 ) ;
V_49 = V_19 -> V_28 - V_43 ;
V_46 = F_35 ( F_17 ( V_4 ) ) ;
V_46 -> V_51 ( V_19 , V_42 , V_47 , & V_47 -> V_52 ,
V_49 , V_48 ) ;
if ( V_44 && V_24 != V_22 )
F_25 ( V_4 , V_6 , V_47 -> V_1 ,
( int ) V_24 - ( int ) V_22 ) ;
return 1 ;
}
int
F_36 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
enum V_5 V_6 ,
unsigned int V_43 ,
unsigned int V_21 ,
unsigned int V_22 ,
const char * V_23 ,
unsigned int V_24 )
{
const struct V_45 * V_46 ;
struct V_53 * V_54 ;
int V_49 , V_48 ;
if ( ! F_33 ( V_19 , V_19 -> V_28 ) )
return 0 ;
if ( V_24 > V_22 &&
V_24 - V_22 > F_24 ( V_19 ) &&
! F_22 ( V_19 , V_24 - V_22 ) )
return 0 ;
V_54 = ( void * ) V_19 -> V_25 + V_43 ;
V_48 = V_19 -> V_28 - V_43 ;
F_11 ( V_19 , V_43 + sizeof( * V_54 ) ,
V_21 , V_22 , V_23 , V_24 ) ;
V_49 = V_19 -> V_28 - V_43 ;
V_54 -> V_28 = F_19 ( V_49 ) ;
if ( ! V_54 -> V_52 && V_19 -> V_55 != V_56 )
return 1 ;
V_46 = F_35 ( F_17 ( V_4 ) ) ;
V_46 -> V_51 ( V_19 , V_57 , V_54 , & V_54 -> V_52 ,
V_49 , V_48 ) ;
return 1 ;
}
static void
F_37 ( struct V_18 * V_19 ,
struct V_40 * V_47 ,
unsigned int V_58 ,
unsigned int V_59 ,
struct V_11 * V_60 )
{
while ( V_58 < V_59 ) {
struct V_61 * V_62 ;
T_3 V_63 , V_64 ;
V_62 = ( void * ) V_19 -> V_25 + V_58 ;
if ( F_10 ( F_27 ( V_62 -> V_65 ) - V_60 -> V_14 ,
V_60 -> V_16 ) )
V_63 = F_38 ( F_27 ( V_62 -> V_65 )
- V_60 -> V_15 ) ;
else
V_63 = F_38 ( F_27 ( V_62 -> V_65 )
- V_60 -> V_14 ) ;
if ( F_10 ( F_27 ( V_62 -> V_66 ) - V_60 -> V_14 ,
V_60 -> V_16 ) )
V_64 = F_38 ( F_27 ( V_62 -> V_66 )
- V_60 -> V_15 ) ;
else
V_64 = F_38 ( F_27 ( V_62 -> V_66 )
- V_60 -> V_14 ) ;
F_4 ( L_7 ,
F_27 ( V_62 -> V_65 ) , V_63 ,
F_27 ( V_62 -> V_66 ) , V_64 ) ;
F_39 ( & V_47 -> V_52 , V_19 ,
V_62 -> V_65 , V_63 , 0 ) ;
F_39 ( & V_47 -> V_52 , V_19 ,
V_62 -> V_66 , V_64 , 0 ) ;
V_62 -> V_65 = V_63 ;
V_62 -> V_66 = V_64 ;
V_58 += sizeof( * V_62 ) ;
}
}
static inline unsigned int
F_40 ( struct V_18 * V_19 ,
unsigned int V_43 ,
struct V_40 * V_47 ,
struct V_3 * V_4 ,
enum V_5 V_6 )
{
unsigned int V_8 , V_67 , V_68 ;
struct V_9 * V_10 = F_3 ( V_4 ) ;
V_67 = V_43 + sizeof( struct V_40 ) ;
V_68 = V_43 + V_47 -> V_50 * 4 ;
if ( ! F_33 ( V_19 , V_68 ) )
return 0 ;
V_8 = F_2 ( V_6 ) ;
while ( V_67 < V_68 ) {
unsigned char * V_69 = V_19 -> V_25 + V_67 ;
switch ( V_69 [ 0 ] ) {
case V_70 :
return 1 ;
case V_71 :
V_67 ++ ;
continue;
default:
if ( V_67 + 1 == V_68 ||
V_67 + V_69 [ 1 ] > V_68 ||
V_69 [ 1 ] < 2 )
return 0 ;
if ( V_69 [ 0 ] == V_72 &&
V_69 [ 1 ] >= 2 + V_73 &&
( ( V_69 [ 1 ] - 2 ) % V_73 ) == 0 )
F_37 ( V_19 , V_47 , V_67 + 2 ,
V_67 + V_69 [ 1 ] , & V_10 -> V_1 [ ! V_8 ] ) ;
V_67 += V_69 [ 1 ] ;
}
}
return 1 ;
}
int
F_41 ( struct V_18 * V_19 ,
struct V_3 * V_4 ,
enum V_5 V_6 ,
unsigned int V_43 )
{
struct V_40 * V_47 ;
int V_8 ;
T_3 V_74 , V_75 ;
T_2 V_76 , V_77 ;
struct V_9 * V_10 = F_3 ( V_4 ) ;
struct V_11 * V_12 , * V_78 ;
V_8 = F_2 ( V_6 ) ;
V_12 = & V_10 -> V_1 [ V_8 ] ;
V_78 = & V_10 -> V_1 [ ! V_8 ] ;
if ( ! F_33 ( V_19 , V_43 + sizeof( * V_47 ) ) )
return 0 ;
V_47 = ( void * ) V_19 -> V_25 + V_43 ;
if ( F_10 ( F_27 ( V_47 -> V_1 ) , V_12 -> V_16 ) )
V_76 = V_12 -> V_15 ;
else
V_76 = V_12 -> V_14 ;
if ( F_10 ( F_27 ( V_47 -> V_79 ) - V_78 -> V_14 ,
V_78 -> V_16 ) )
V_77 = V_78 -> V_15 ;
else
V_77 = V_78 -> V_14 ;
V_74 = F_38 ( F_27 ( V_47 -> V_1 ) + V_76 ) ;
V_75 = F_38 ( F_27 ( V_47 -> V_79 ) - V_77 ) ;
F_39 ( & V_47 -> V_52 , V_19 , V_47 -> V_1 , V_74 , 0 ) ;
F_39 ( & V_47 -> V_52 , V_19 , V_47 -> V_79 , V_75 , 0 ) ;
F_4 ( L_8 ,
F_27 ( V_47 -> V_1 ) , F_27 ( V_74 ) , F_27 ( V_47 -> V_79 ) ,
F_27 ( V_75 ) ) ;
V_47 -> V_1 = V_74 ;
V_47 -> V_79 = V_75 ;
return F_40 ( V_19 , V_43 , V_47 , V_4 , V_6 ) ;
}
void F_42 ( struct V_3 * V_4 ,
struct V_80 * exp )
{
struct V_81 V_82 ;
F_12 ( V_4 -> V_38 & V_83 ) ;
V_82 . V_84 = V_85 ;
V_82 . V_86 = V_82 . V_87
= V_4 -> V_88 -> V_89 [ ! exp -> V_8 ] . V_90 . V_91 . V_92 ;
F_43 ( V_4 , & V_82 , V_93 ) ;
V_82 . V_84 = ( V_85 | V_94 ) ;
V_82 . V_95 = V_82 . V_96 = exp -> V_97 ;
V_82 . V_86 = V_82 . V_87
= V_4 -> V_88 -> V_89 [ ! exp -> V_8 ] . V_90 . V_98 . V_92 ;
F_43 ( V_4 , & V_82 , V_99 ) ;
}
