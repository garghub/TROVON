static enum V_1
F_1 ( void * V_2 ,
enum V_3 V_3 ,
struct V_4 * V_4 )
{
void * V_5 = NULL ;
V_5 = V_2 ;
if ( ! V_4 )
return V_6 ;
if ( V_3 == V_7 ) {
if ( ! V_4 -> V_8 ) {
F_2 ( L_1 ) ;
return V_6 ;
}
if ( ! V_4 -> V_9 ) {
F_2 ( L_2 ) ;
return V_6 ;
}
if ( ! V_4 -> V_10 ) {
F_2 ( L_3 ) ;
return V_6 ;
}
if ( ! V_4 -> V_11 ) {
F_2 ( L_4 ) ;
return V_6 ;
}
if ( ! V_4 -> V_12 ) {
F_2 ( L_5 ) ;
return V_6 ;
}
if ( ! V_4 -> V_13 ) {
F_2 ( L_6 ) ;
return V_6 ;
}
if ( ! V_4 -> V_14 ) {
F_2 ( L_7 ) ;
return V_6 ;
}
if ( ! V_4 -> V_15 ) {
F_2 ( L_8 ) ;
return V_6 ;
}
if ( ! V_4 -> V_16 ) {
F_2 ( L_9 ) ;
return V_6 ;
}
}
if ( V_3 == V_17 ||
V_3 == V_18 ) {
if ( ! V_4 -> V_19 ) {
F_2 ( L_10 ) ;
return V_6 ;
}
if ( ! V_4 -> V_20 ) {
F_2 ( L_11 ) ;
return V_6 ;
}
if ( ! V_4 -> V_21 ) {
F_2 ( L_12 ) ;
return V_6 ;
}
if ( ! V_4 -> V_22 ) {
F_2 ( L_13 ) ;
return V_6 ;
}
if ( ! V_4 -> V_23 ) {
F_2 ( L_14 ) ;
return V_6 ;
}
if ( ! V_4 -> V_24 ) {
F_2 ( L_15 ) ;
return V_6 ;
}
}
if ( ! V_4 -> V_25 ) {
F_2 ( L_16 ) ;
return V_6 ;
}
F_3 ( V_2 , V_26 , V_27 ,
L_17 , V_28 ) ;
return V_29 ;
}
static enum V_1
F_4 ( T_1 * V_30 )
{
switch ( ( * V_30 ) & 0xFFFF0000 ) {
case V_31 :
* V_30 = ( V_32 << 13 ) |
( * V_30 & V_33 ) ;
break;
case V_34 :
* V_30 = ( V_35 << 13 ) |
( * V_30 & V_36 ) ;
break;
default:
* V_30 = 0xFFFFFFFF ;
return V_37 ;
}
return V_29 ;
}
static T_2
F_5 ( void * V_2 ,
struct V_4 * V_4 ,
T_1 V_38 )
{
T_2 V_39 ;
T_1 V_30 = V_38 ;
enum V_1 V_40 = V_29 ;
if ( ( V_30 & 0xFFFF0000 ) == 0 )
V_30 |= V_31 ;
V_40 = F_4 ( & V_30 ) ;
if ( V_40 != V_29 ) {
F_2 ( L_18 , V_28 , V_40 ) ;
return V_40 ;
}
V_39 = V_4 -> V_8 ( V_2 ,
V_30 ) ;
return V_39 ;
}
static enum V_1
F_6 ( void * V_2 ,
struct V_4 * V_4 ,
T_1 V_38 , T_2 V_41 )
{
enum V_1 V_40 = V_29 ;
T_1 V_30 = V_38 ;
if ( ( V_30 & 0xFFFF0000 ) == 0 )
V_30 |= V_31 ;
V_40 = F_4 ( & V_30 ) ;
if ( V_40 != V_29 ) {
F_2 ( L_19 , V_40 ) ;
return V_40 ;
}
V_4 -> V_13 ( V_2 , V_30 ,
V_41 ) ;
return V_29 ;
}
static enum V_1
F_7 ( void * V_2 ,
struct V_4 * V_4 ,
enum V_3 V_3 ,
struct V_42 * V_42 )
{
struct V_43 * V_43 = (struct V_43 * ) NULL ;
T_2 V_44 , V_45 ;
T_1 V_46 ;
V_43 = (struct V_43 * ) V_42 -> V_43 ;
if ( V_42 -> V_3 == V_7 ) {
F_6 (
V_2 , V_4 , V_47 ,
F_5 ( V_2 ,
V_4 ,
V_47 ) &
~ ( F_8 ( 0 ) ) ) ;
V_46 = 10000 ;
while ( ! ( F_5 ( V_2 ,
V_4 ,
V_47 ) &
0x02 ) ) {
V_46 -- ;
if ( V_46 == 0 )
return V_48 ;
}
V_44 = F_5 (
V_2 , V_4 , V_49 ) ;
V_45 = F_5 ( V_2 ,
V_4 ,
V_50 + 1 ) >>
4 ;
} else {
V_44 = V_4 -> V_19 ( V_2 ,
V_49 ) ;
V_45 = V_4 -> V_19 (
V_2 , V_50 + 1 ) >>
4 ;
}
F_3 ( V_2 , V_26 , V_27 ,
L_20 , V_44 ) ;
F_3 ( V_2 , V_26 , V_27 ,
L_21 , V_45 ) ;
V_42 -> V_45 = (enum V_51 ) V_45 ;
if ( V_44 == V_52 )
V_42 -> V_44 = V_53 ;
else if ( V_44 == V_54 )
V_42 -> V_44 = V_55 ;
else if ( V_44 == V_56 )
V_42 -> V_44 = V_57 ;
else if ( V_44 == V_58 )
V_42 -> V_44 = V_59 ;
else
V_42 -> V_44 = V_60 ;
if ( V_42 -> V_44 == V_60 )
return V_61 ;
return V_29 ;
}
enum V_1
F_9 ( void * V_2 ,
struct V_4 * V_4 ,
enum V_3 V_3 ,
struct V_42 * * V_62 ,
struct V_43 * * V_63 )
{
struct V_42 * V_42 = (struct V_42 * ) NULL ;
enum V_1 V_40 = V_29 ;
union {
T_1 V_64 ;
T_2 V_65 [ 4 ] ;
} V_66 = { 0x01000000 } ;
V_40 = F_1 ( V_2 , V_3 ,
V_4 ) ;
if ( V_40 != V_29 )
return V_40 ;
F_3 ( V_2 , V_26 , V_27 ,
V_67 L_22 ) ;
F_3 ( V_2 , V_26 , V_27 ,
L_23 , V_68 ) ;
F_3 ( V_2 , V_26 , V_27 ,
L_24 , V_69 ) ;
F_3 ( V_2 , V_26 , V_27 ,
L_25 , V_70 ) ;
F_3 ( V_2 , V_26 , V_27 ,
L_26 , V_71 ) ;
F_3 ( V_2 , V_26 , V_27 ,
L_27 ) ;
if ( V_66 . V_65 [ 0 ] == V_72 ) {
F_2 ( L_28 ) ;
return V_73 ;
}
V_42 = F_10 ( sizeof( * V_42 ) , V_74 ) ;
if ( ! V_42 ) {
return V_75 ;
}
* V_62 = V_42 ;
V_42 -> V_4 = V_4 ;
V_42 -> V_2 = V_2 ;
V_3 = V_3 == V_76 ?
V_18 :
V_3 ;
V_42 -> V_3 = V_3 ;
F_11 ( & V_42 -> V_77 ) ;
F_11 ( & V_42 -> V_78 ) ;
if ( F_7 ( V_2 , V_4 ,
V_3 ,
V_42 ) != V_29 ) {
F_2 ( L_29 ) ;
return V_61 ;
}
F_12 ( V_42 ) ;
V_40 = F_13 ( V_42 ) ;
* V_63 = (struct V_43 * ) V_42 -> V_43 ;
F_3 ( V_2 , V_26 , V_27 ,
L_30 ) ;
return V_40 ;
}
enum V_1 F_14 ( struct V_42 * V_42 )
{
void * V_2 = NULL ;
struct V_4 * V_4 =
(struct V_4 * ) NULL ;
if ( F_15 ( V_42 ) != V_29 )
return V_79 ;
V_2 = V_42 -> V_2 ;
V_4 = V_42 -> V_4 ;
F_3 ( V_2 , V_26 , V_27 ,
L_17 , V_28 ) ;
V_42 -> V_80 . V_81 = V_82 ;
F_3 ( V_2 , V_26 , V_27 ,
L_17 , V_28 ) ;
return V_29 ;
}
enum V_1
F_16 ( struct V_42 * V_42 )
{
void * V_2 = NULL ;
if ( F_15 ( V_42 ) != V_29 )
return V_79 ;
V_2 = V_42 -> V_2 ;
F_3 ( V_2 , V_26 , V_27 ,
L_31 ) ;
F_17 ( V_42 -> V_83 ) ;
V_42 -> V_83 = ( T_2 * ) NULL ;
F_17 ( V_42 -> V_80 . V_84 . V_41 ) ;
V_42 -> V_80 . V_84 . V_41 = ( T_2 * ) NULL ;
F_17 ( V_42 -> V_43 ) ;
V_42 -> V_43 = NULL ;
V_42 -> V_85 = NULL ;
F_17 ( V_42 ) ;
return V_29 ;
}
enum V_1 F_18 ( struct V_86 * V_87 )
{
V_87 -> V_88 = ( T_2 ) V_68 ;
V_87 -> V_89 = ( T_2 ) V_69 ;
V_87 -> V_90 = ( T_2 ) V_70 ;
return V_29 ;
}
