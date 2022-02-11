void F_1 ( struct V_1 * V_2 )
{
V_2 -> V_3 . V_4 = V_5 ;
V_2 -> V_3 . V_6 = 0 ;
V_2 -> V_3 . V_7 = 0 ;
V_2 -> V_8 . V_9 = F_2 ( V_10 ) ;
V_2 -> V_3 . V_11 = FALSE ;
}
void F_3 ( struct V_1 * V_2 , int V_12 )
{
int V_13 ;
do {
F_4 ( L_1 ,
( V_2 -> V_8 . V_9 & V_14 ) ? L_2 : L_3 ,
V_15 [ V_2 -> V_8 . V_9 & ~ V_14 ] ) ;
F_4 ( L_4 , V_16 [ V_12 ] , 0 ) ;
V_13 = V_2 -> V_8 . V_9 ;
F_5 ( V_2 , V_12 ) ;
V_12 = 0 ;
} while ( V_13 != V_2 -> V_8 . V_9 ) ;
F_6 ( V_2 , ( int ) V_2 -> V_8 . V_9 ) ;
}
static void F_5 ( struct V_1 * V_2 , int V_17 )
{
int V_18 ;
int V_19 ;
int V_20 ;
V_2 -> V_8 . V_21 = F_7 ( V_2 ) ;
if ( V_17 == V_22 )
V_2 -> V_8 . V_23 = FALSE ;
if ( V_17 == V_24 &&
V_2 -> V_8 . V_23 == TRUE )
F_8 ( V_2 , ( V_25 ) V_26 , ( V_25 )
V_27 , F_9 ( V_2 ) ,
F_10 ( V_2 ) ) ;
if ( V_17 == V_22 ) {
V_2 -> V_3 . V_28 = FALSE ;
}
else if ( V_17 == V_24 ) {
V_2 -> V_3 . V_28 = TRUE ;
}
switch( V_2 -> V_8 . V_9 ) {
case F_2 ( V_10 ) :
V_2 -> V_3 . V_4 = V_5 ;
V_2 -> V_3 . V_11 = FALSE ;
F_11 ( V_2 ) ;
F_12 () ;
break ;
case V_10 :
if ( V_17 == V_22 && ! V_2 -> V_8 . V_21
&& V_2 -> V_3 . V_4 == V_5 ) {
F_13 ( V_29 ) ;
break ;
}
else if ( V_17 == V_22 && ( V_2 -> V_3 . V_4 == V_5 ) &&
V_2 -> V_8 . V_21 &&
( V_2 -> V_30 . V_31 == V_32 ) ) {
F_13 ( V_33 ) ;
break ;
}
break;
case F_2 ( V_29 ) :
F_11 ( V_2 ) ;
V_2 -> V_3 . V_6 = 0 ;
F_14 ( V_2 , V_34 ) ;
for ( V_20 = 0 ; V_20 < V_35 ; V_20 ++ )
if ( V_2 -> V_8 . V_20 [ V_20 ] . V_36 )
F_15 ( V_2 , V_37 + V_20 , V_38 ) ;
F_12 () ;
break ;
case V_29 :
if ( V_17 == V_39 ) {
F_16 ( V_2 ) ;
F_13 ( V_40 ) ;
break ;
}
else if ( V_17 == V_24 ) {
F_13 ( V_41 ) ;
break ;
}
break;
case F_2 ( V_40 ) :
F_17 ( V_2 , F_18 ( V_2 -> V_8 . V_42 ) ,
V_43 ) ;
F_12 () ;
break ;
case V_40 :
if ( V_17 == V_39 ) {
F_16 ( V_2 ) ;
F_13 ( V_40 ) ;
break ;
}
else if ( V_17 == V_24 ) {
V_2 -> V_3 . V_4 = V_44 ;
F_13 ( V_41 ) ;
break ;
}
else if ( V_2 -> V_3 . V_4 == V_45 ) {
F_13 ( V_41 ) ;
break ;
}
else if ( V_17 == V_43 ) {
F_8 ( V_2 , ( V_25 ) V_46 ,
( V_25 ) V_47 , ( V_25 )
V_48 , F_10 ( V_2 ) ) ;
V_2 -> V_3 . V_4 = V_45 ;
F_13 ( V_41 ) ;
break ;
}
break ;
case F_2 ( V_41 ) :
F_17 ( V_2 , V_2 -> V_30 . V_49 , V_50 ) ;
for ( V_20 = 0 ; V_20 < V_35 ; V_20 ++ )
F_15 ( V_2 , V_37 + V_20 , V_51 ) ;
F_12 () ;
break ;
case V_41 :
if ( V_17 == V_50 && ! V_2 -> V_8 . V_21 &&
( V_2 -> V_3 . V_4 != V_45 ) ) {
F_13 ( V_10 ) ;
break ;
}
else if ( V_17 == V_50 &&
( V_2 -> V_3 . V_4 == V_45 ) ) {
F_13 ( V_52 ) ;
break ;
}
else if ( V_17 == V_22 && V_2 -> V_3 . V_4 == V_5 ) {
F_13 ( V_29 ) ;
break ;
}
else if ( V_17 == V_24 &&
V_2 -> V_3 . V_4 == V_45 ) {
V_2 -> V_3 . V_4 = V_44 ;
}
else if ( V_17 == V_50 &&
V_2 -> V_8 . V_21 &&
V_2 -> V_3 . V_4 != V_45 ) {
F_13 ( V_53 ) ;
break ;
}
break ;
case F_2 ( V_52 ) :
F_11 ( V_2 ) ;
V_2 -> V_3 . V_4 = V_54 ;
F_17 ( V_2 , V_2 -> V_30 . V_55 , V_56 ) ;
F_12 () ;
break ;
case V_52 :
if ( V_17 == V_56 )
V_2 -> V_3 . V_4 = V_5 ;
if ( V_2 -> V_3 . V_4 == V_57 )
F_19 ( V_2 , V_58 ) ;
if ( V_2 -> V_3 . V_4 == V_57 &&
! V_2 -> V_8 . V_21 ) {
F_13 ( V_10 ) ;
break ;
}
else if ( V_17 == V_24 &&
! V_2 -> V_8 . V_21 ) {
F_13 ( V_10 ) ;
break ;
}
else if ( V_2 -> V_3 . V_4 == V_5 ) {
F_13 ( V_29 ) ;
break ;
}
else if ( V_2 -> V_3 . V_4 == V_57 &&
V_2 -> V_8 . V_21 ) {
F_13 ( V_53 ) ;
break ;
}
else if ( V_17 == V_24 &&
V_2 -> V_8 . V_21 ) {
F_13 ( V_53 ) ;
break ;
}
break ;
case F_2 ( V_33 ) :
F_20 ( V_2 , V_59 ) ;
F_17 ( V_2 , V_2 -> V_30 . V_60 , V_61 ) ;
F_12 () ;
break ;
case V_33 :
if ( V_17 == V_61 ) {
F_13 ( V_62 ) ;
break ;
}
else if ( V_17 == V_24 ) {
F_13 ( V_53 ) ;
break ;
}
break ;
case F_2 ( V_62 ) :
F_17 ( V_2 , V_2 -> V_30 . V_63 , 0 ) ;
V_2 -> V_3 . V_11 = TRUE ;
( void ) F_21 ( V_2 , V_64 , 1 ) ;
( void ) F_21 ( V_2 , V_65 , 1 ) ;
F_12 () ;
break ;
case V_62 :
V_18 = F_22 ( V_2 , V_64 ) ;
V_19 = F_22 ( V_2 , V_65 ) ;
if ( ( ( V_18 == V_66 ) || ( V_18 == V_67 ) ) &&
( ( V_19 == V_66 ) || ( V_19 == V_67 ) ) ) {
V_2 -> V_3 . V_7 = FALSE ;
V_2 -> V_3 . V_11 = FALSE ;
F_13 ( V_29 ) ;
break ;
}
else if ( ! V_2 -> V_3 . V_7 &&
( ( ( V_18 == V_68 ) && ( V_19 == V_66 ) ) ||
( ( V_18 == V_66 ) && ( V_19 == V_68 ) ) ) ) {
V_2 -> V_3 . V_7 = TRUE ;
F_23 ( 1 , L_5 , 0 , 0 ) ;
F_8 ( V_2 , ( V_25 ) V_46 , ( V_25 )
V_47 , ( V_25 ) V_69 ,
F_10 ( V_2 ) ) ;
}
else if ( V_17 == V_24 ) {
V_2 -> V_3 . V_11 = FALSE ;
F_13 ( V_53 ) ;
break ;
}
else {
F_17 ( V_2 , V_2 -> V_30 . V_63 , 0 ) ;
}
break ;
case F_2 ( V_53 ) :
F_20 ( V_2 , V_70 ) ;
F_17 ( V_2 , V_2 -> V_30 . V_71 , V_72 ) ;
F_12 () ;
break ;
case V_53 :
if ( V_17 == V_72 ) {
F_13 ( V_10 ) ;
break ;
}
else if ( V_17 == V_22 && V_2 -> V_3 . V_4 == V_5 ) {
F_13 ( V_33 ) ;
break ;
}
break;
default:
F_24 ( V_2 , V_73 , V_74 ) ;
break;
}
}
static void F_16 ( struct V_1 * V_2 )
{
int V_75 = 0 ;
int V_76 = 0 ;
F_19 ( V_2 , V_77 ) ;
switch ( V_2 -> V_30 . V_31 ) {
case V_78 :
V_75 = V_76 = F_25 ( V_2 ) ;
break ;
case V_32 :
V_75 = F_26 ( V_2 ) ;
V_76 = F_27 ( V_2 ) ;
break ;
case V_79 :
F_24 ( V_2 , V_80 , V_81 ) ;
return ;
}
F_4 ( L_6 , V_2 -> V_3 . V_6 , 0 ) ;
F_4 ( L_7 , V_75 , V_76 ) ;
if ( V_2 -> V_3 . V_6 & F_28 ( V_82 ) ) {
F_4 ( L_8 , 'A' + V_75 - V_64 , 0 ) ;
F_15 ( V_2 , V_83 + V_75 , V_84 ) ;
}
else if ( ( V_2 -> V_3 . V_6 & F_28 ( F_29 ( V_64 ) ) ) &&
V_76 != V_64 ) {
F_4 ( L_9 , 0 , 0 ) ;
F_15 ( V_2 , V_85 , V_84 ) ;
}
else if ( ( V_2 -> V_3 . V_6 & F_28 ( F_29 ( V_65 ) ) ) &&
V_76 != V_65 ) {
F_4 ( L_10 , 0 , 0 ) ;
F_15 ( V_2 , V_37 , V_84 ) ;
}
else {
F_4 ( L_11 , 0 , 0 ) ;
V_2 -> V_3 . V_4 = V_45 ;
}
V_2 -> V_3 . V_6 = 0 ;
}
static void F_16 ( struct V_1 * V_2 )
{
int V_86 ;
int V_87 ;
int V_20 ;
F_19 ( V_2 , V_77 ) ;
while ( V_2 -> V_3 . V_6 ) {
F_4 ( L_6 ,
V_2 -> V_3 . V_6 , 0 ) ;
if ( V_2 -> V_3 . V_6 & F_28 ( V_82 ) ) {
V_86 = V_82 ;
V_2 -> V_3 . V_6 &= ~ F_28 ( V_82 ) ;
F_4 ( L_12 , 0 , 0 ) ;
}
else {
for ( V_20 = V_35 - 1 ; V_20 >= 0 ; V_20 -- ) {
if ( V_2 -> V_3 . V_6 &
F_28 ( F_29 ( V_20 ) ) )
break ;
}
V_86 = F_29 ( V_20 ) ;
V_2 -> V_3 . V_6 &= ~ F_28 ( F_29 ( V_20 ) ) ;
}
V_87 = F_30 ( V_2 , V_86 ) ;
if ( V_87 == V_82 ) {
F_4 ( L_11 , 0 , 0 ) ;
V_2 -> V_3 . V_4 = V_45 ;
}
else {
F_4 ( L_13 , V_87 , 0 ) ;
F_15 ( V_2 , V_83 + V_87 , V_84 ) ;
}
}
}
static void F_17 ( struct V_1 * V_2 , V_25 V_88 , int V_12 )
{
F_31 ( V_2 , & V_2 -> V_3 . V_89 , V_88 , F_32 ( V_90 , V_12 ) ) ;
}
static void F_11 ( struct V_1 * V_2 )
{
if ( V_2 -> V_3 . V_89 . V_91 )
F_33 ( V_2 , & V_2 -> V_3 . V_89 ) ;
}
