static void F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = V_2 -> V_6 ;
V_2 -> V_7 &= ~ V_8 ;
V_2 -> V_9 = NULL ;
V_2 -> V_10 = NULL ;
V_5 -> V_11 . V_12 ( & V_5 -> V_11 , V_3 ) ;
}
static void F_2 ( struct V_1 * V_2 )
{
T_1 * V_13 ;
int V_14 , V_15 , V_16 , V_3 = 0 , V_17 ;
struct V_18 * V_19 ;
V_14 = F_3 ( V_2 -> V_20 , V_21 ) ;
V_15 = F_3 ( V_2 -> V_22 , V_21 ) ;
V_19 = F_4 ( V_2 -> V_6 ) ;
V_17 = ! ! ( V_2 -> V_20 && V_2 -> V_22 ) ;
F_5 ( V_2 -> V_23 , V_2 -> V_10 , V_2 -> V_24 ,
V_25 ) ;
F_6 ( V_2 -> V_23 , V_2 -> V_9 , V_2 -> V_26 , V_27 ) ;
F_6 ( V_2 -> V_23 , V_2 -> V_10 , V_2 -> V_24 , V_25 ) ;
F_7 ( V_2 ) ;
F_8 ( V_2 -> V_10 , V_2 -> V_28 ,
V_2 -> V_6 -> V_29 , V_2 -> V_22 ,
V_30 , V_2 -> V_7 ) ;
if ( V_2 -> V_7 & V_31 )
F_9 ( V_19 -> V_32 ,
V_2 -> V_6 -> V_33 ,
V_2 -> V_22 + V_2 -> V_6 -> V_29 ,
V_2 -> V_34 , 1 ) ;
F_8 ( & V_2 -> V_35 [ 0 ] , NULL , 0 , V_14 ,
V_36 , V_2 -> V_7 ) ;
F_8 ( & V_2 -> V_35 [ V_17 ] , NULL , 0 , V_15 ,
V_37 , V_2 -> V_7 ) ;
if ( ! ( V_2 -> V_7 & V_31 ) ) {
V_13 = ( T_1 * ) V_19 -> V_32 ;
for ( V_16 = 0 ; V_16 < V_2 -> V_34 ; V_16 ++ ) {
if ( V_13 [ V_16 ] ) {
F_10 ( V_2 -> V_23 , L_1 ) ;
V_3 = - V_38 ;
}
}
}
F_1 ( V_2 , V_3 ) ;
F_11 ( V_2 , NULL ) ;
}
static int F_12 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
int V_14 , V_15 , V_39 , V_29 , V_3 ;
struct V_40 * V_41 = F_13 ( V_5 ) ;
unsigned int V_42 = F_14 ( V_41 ) ;
struct V_43 * V_44 , V_45 [ 2 ] ;
int V_17 ;
T_2 V_7 ;
V_29 = V_5 -> V_29 ;
V_39 = V_5 -> V_39 ;
if ( V_2 -> V_7 & V_46 )
V_29 -= 8 ;
if ( ! ( V_2 -> V_7 & V_31 ) )
V_39 -= V_42 ;
V_14 = F_3 ( V_29 , V_21 ) ;
V_15 = F_3 ( V_39 , V_21 ) ;
V_17 = ! ! ( V_29 && V_39 ) ;
F_15 ( V_2 ) ;
F_16 ( V_2 -> V_35 , V_17 + 1 ) ;
if ( V_29 ) {
V_44 = V_5 -> V_47 ;
V_3 = F_17 ( & V_44 , V_29 ,
V_21 , V_2 -> V_35 ,
V_48 |
V_49 |
V_50 ,
V_36 ,
& V_2 -> V_7 ) ;
}
if ( V_39 ) {
V_44 = F_18 ( V_45 , V_5 -> V_47 , V_5 -> V_29 ) ;
V_3 = F_17 ( & V_44 , V_39 ,
V_21 , & V_2 -> V_35 [ V_17 ] ,
V_48 |
V_49 |
V_50 ,
V_37 ,
& V_2 -> V_7 ) ;
}
V_2 -> V_9 = V_2 -> V_35 ;
V_2 -> V_22 = V_39 ;
V_2 -> V_20 = V_29 ;
V_2 -> V_34 = V_42 ;
V_2 -> V_10 = V_5 -> V_33 ;
V_2 -> V_28 = V_5 -> V_33 ;
V_2 -> V_10 = F_18 ( V_45 , V_5 -> V_33 , V_29 ) ;
V_7 = 0 ;
if ( V_5 -> V_47 == V_5 -> V_33 || V_2 -> V_10 == V_45 )
V_7 |= V_51 ;
V_3 = F_17 ( & V_2 -> V_10 , V_39 ,
V_21 , & V_2 -> V_52 ,
V_7 ,
V_30 , & V_2 -> V_7 ) ;
if ( V_3 )
return V_3 ;
V_2 -> V_26 = F_19 ( V_2 -> V_9 , V_14 + V_15 ) ;
V_2 -> V_24 = F_19 ( V_2 -> V_10 , V_15 ) ;
return 0 ;
}
static void F_20 ( struct V_53 * V_5 , int V_54 )
{
struct V_55 * V_56 = V_5 -> V_57 ;
if ( V_54 == - V_58 )
return;
V_56 -> V_54 = V_54 ;
V_12 ( & V_56 -> V_59 ) ;
}
static int F_21 ( struct V_4 * V_5 , T_3 * V_13 , T_3 * V_60 )
{
struct V_43 V_61 , V_62 ;
struct V_63 * V_64 ;
struct V_55 V_65 ;
struct V_66 * V_67 = F_22 ( F_13 ( V_5 ) ) ;
int V_3 = 0 ;
V_64 = F_23 ( V_67 -> V_68 , V_69 ) ;
if ( ! V_64 ) {
F_24 ( L_2 ) ;
return - 1 ;
}
F_25 ( & V_65 . V_59 ) ;
F_26 ( & V_61 , V_60 , V_21 ) ;
F_26 ( & V_62 , V_13 , V_21 ) ;
F_27 ( V_64 , V_70 ,
F_20 , & V_65 ) ;
V_3 = F_28 ( V_67 -> V_68 , ( T_1 * ) V_67 -> V_71 , V_67 -> V_72 ) ;
F_29 ( V_64 , & V_61 , & V_62 , V_21 ,
NULL ) ;
V_3 = F_30 ( V_64 ) ;
switch ( V_3 ) {
case 0 :
break;
case - V_58 :
case - V_73 :
V_3 = F_31 ( & V_65 . V_59 ) ;
if ( ! V_3 ) {
V_3 = V_65 . V_54 ;
if ( ! V_3 ) {
F_32 ( & V_65 . V_59 ) ;
break;
}
}
default:
F_24 ( L_3 ) ;
break;
}
F_33 ( V_64 ) ;
return V_3 ;
}
void F_34 ( void * V_57 )
{
struct V_1 * V_2 = V_57 ;
struct V_18 * V_19 ;
int V_16 , V_74 ;
T_3 * V_32 , V_13 [ 4 ] ;
if ( ! ( V_2 -> V_7 & V_31 ) )
F_9 ( V_13 , V_2 -> V_6 -> V_47 ,
V_2 -> V_22 + V_2 -> V_6 -> V_29 ,
V_2 -> V_34 , 0 ) ;
V_19 = F_4 ( V_2 -> V_6 ) ;
V_32 = ( T_3 * ) V_19 -> V_32 ;
for ( V_16 = 0 ; V_16 < 4 ; V_16 ++ ) {
V_74 = F_35 ( V_2 , F_36 ( V_2 , V_16 ) ) ;
V_32 [ V_16 ] = V_74 ^ V_32 [ V_16 ] ;
if ( ! ( V_2 -> V_7 & V_31 ) )
V_32 [ V_16 ] = V_32 [ V_16 ] ^ V_13 [ V_16 ] ;
}
F_2 ( V_2 ) ;
}
static int F_11 ( struct V_1 * V_2 ,
struct V_4 * V_5 )
{
struct V_66 * V_67 ;
struct V_4 * V_75 ;
struct V_18 * V_19 ;
unsigned long V_7 ;
int V_54 , V_3 = 0 ;
F_37 ( & V_2 -> V_76 , V_7 ) ;
if ( V_5 )
V_3 = F_38 ( & V_2 -> V_77 , V_5 ) ;
if ( V_2 -> V_7 & V_8 ) {
F_39 ( & V_2 -> V_76 , V_7 ) ;
return V_3 ;
}
V_75 = F_40 ( & V_2 -> V_77 ) ;
V_5 = F_41 ( & V_2 -> V_77 ) ;
if ( V_5 )
V_2 -> V_7 |= V_8 ;
F_39 ( & V_2 -> V_76 , V_7 ) ;
if ( ! V_5 )
return V_3 ;
if ( V_75 )
V_75 -> V_11 . V_12 ( & V_75 -> V_11 , - V_58 ) ;
V_67 = F_22 ( F_13 ( V_5 ) ) ;
V_19 = F_4 ( V_5 ) ;
V_2 -> V_67 = V_67 ;
V_19 -> V_2 = V_2 ;
V_2 -> V_6 = V_5 ;
V_19 -> V_78 &= V_79 ;
V_2 -> V_7 = ( V_2 -> V_7 & ~ V_79 ) | V_19 -> V_78 ;
V_54 = F_12 ( V_2 , V_5 ) ;
if ( V_54 )
return V_54 ;
V_54 = F_42 ( V_2 ) ;
if ( ! V_54 )
V_54 = F_43 ( V_2 ) ;
if ( V_54 ) {
F_1 ( V_2 , V_54 ) ;
F_11 ( V_2 , NULL ) ;
}
return V_3 ;
}
static int F_44 ( struct V_4 * V_5 , unsigned long V_78 )
{
struct V_18 * V_19 = F_4 ( V_5 ) ;
struct V_40 * V_41 = F_13 ( V_5 ) ;
unsigned int V_42 = F_14 ( V_41 ) ;
struct V_1 * V_2 ;
T_4 V_80 = F_45 ( 1 ) ;
int V_54 , V_29 ;
memset ( V_19 -> V_32 , 0 , sizeof( V_19 -> V_32 ) ) ;
memcpy ( V_19 -> V_60 + 12 , & V_80 , 4 ) ;
V_54 = F_21 ( V_5 , ( T_3 * ) V_19 -> V_32 , ( T_3 * ) V_19 -> V_60 ) ;
if ( V_54 )
return V_54 ;
if ( V_78 & V_46 )
V_29 = V_5 -> V_29 - 8 ;
else
V_29 = V_5 -> V_29 ;
if ( V_29 + V_5 -> V_39 == 0 ) {
F_9 ( V_19 -> V_32 , V_5 -> V_33 , 0 , V_42 ,
1 ) ;
return 0 ;
}
V_2 = F_46 ( V_19 ) ;
if ( ! V_2 )
return - V_81 ;
V_19 -> V_78 = V_78 ;
return F_11 ( V_2 , V_5 ) ;
}
int F_47 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = F_4 ( V_5 ) ;
memcpy ( V_19 -> V_60 , V_5 -> V_60 , 12 ) ;
return F_44 ( V_5 , V_31 | V_82 ) ;
}
int F_48 ( struct V_4 * V_5 )
{
struct V_18 * V_19 = F_4 ( V_5 ) ;
memcpy ( V_19 -> V_60 , V_5 -> V_60 , 12 ) ;
return F_44 ( V_5 , V_82 ) ;
}
int F_49 ( struct V_4 * V_5 )
{
struct V_66 * V_67 = F_22 ( F_13 ( V_5 ) ) ;
struct V_18 * V_19 = F_4 ( V_5 ) ;
memcpy ( V_19 -> V_60 , V_67 -> V_83 , 4 ) ;
memcpy ( V_19 -> V_60 + 4 , V_5 -> V_60 , 8 ) ;
return F_44 ( V_5 , V_31 | V_82 |
V_46 ) ;
}
int F_50 ( struct V_4 * V_5 )
{
struct V_66 * V_67 = F_22 ( F_13 ( V_5 ) ) ;
struct V_18 * V_19 = F_4 ( V_5 ) ;
memcpy ( V_19 -> V_60 , V_67 -> V_83 , 4 ) ;
memcpy ( V_19 -> V_60 + 4 , V_5 -> V_60 , 8 ) ;
return F_44 ( V_5 , V_82 | V_46 ) ;
}
int F_51 ( struct V_40 * V_84 , const T_1 * V_71 ,
unsigned int V_72 )
{
struct V_66 * V_67 = F_22 ( V_84 ) ;
if ( V_72 != V_85 && V_72 != V_86 &&
V_72 != V_87 )
return - V_88 ;
memcpy ( V_67 -> V_71 , V_71 , V_72 ) ;
V_67 -> V_72 = V_72 ;
return 0 ;
}
int F_52 ( struct V_40 * V_84 , const T_1 * V_71 ,
unsigned int V_72 )
{
struct V_66 * V_67 = F_22 ( V_84 ) ;
if ( V_72 < 4 )
return - V_88 ;
V_72 -= 4 ;
if ( V_72 != V_85 && V_72 != V_86 &&
V_72 != V_87 )
return - V_88 ;
memcpy ( V_67 -> V_71 , V_71 , V_72 ) ;
memcpy ( V_67 -> V_83 , V_71 + V_72 , 4 ) ;
V_67 -> V_72 = V_72 ;
return 0 ;
}
