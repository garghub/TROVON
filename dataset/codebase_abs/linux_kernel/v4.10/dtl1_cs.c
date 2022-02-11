static int F_1 ( unsigned int V_1 , int V_2 , T_1 * V_3 , int V_4 )
{
int V_5 = 0 ;
if ( ! ( F_2 ( V_1 + V_6 ) & V_7 ) )
return 0 ;
while ( ( V_2 -- > 0 ) && ( V_5 < V_4 ) ) {
F_3 ( V_3 [ V_5 ] , V_1 + V_8 ) ;
V_5 ++ ;
}
return V_5 ;
}
static void F_4 ( struct V_9 * V_10 )
{
if ( ! V_10 ) {
F_5 ( L_1 ) ;
return;
}
if ( F_6 ( V_11 , & ( V_10 -> V_12 ) ) ) {
F_7 ( V_13 , & ( V_10 -> V_12 ) ) ;
return;
}
if ( F_8 ( V_14 , & ( V_10 -> V_12 ) ) ) {
F_7 ( V_13 , & ( V_10 -> V_12 ) ) ;
return;
}
do {
unsigned int V_1 = V_10 -> V_15 -> V_16 [ 0 ] -> V_17 ;
register struct V_18 * V_19 ;
int V_4 ;
F_9 ( V_13 , & ( V_10 -> V_12 ) ) ;
if ( ! F_10 ( V_10 -> V_15 ) )
return;
V_19 = F_11 ( & ( V_10 -> V_20 ) ) ;
if ( ! V_19 )
break;
V_4 = F_1 ( V_1 , 32 , V_19 -> V_21 , V_19 -> V_4 ) ;
if ( V_4 == V_19 -> V_4 ) {
F_7 ( V_11 , & ( V_10 -> V_12 ) ) ;
F_12 ( V_19 ) ;
} else {
F_13 ( V_19 , V_4 ) ;
F_14 ( & ( V_10 -> V_20 ) , V_19 ) ;
}
V_10 -> V_22 -> V_23 . V_24 += V_4 ;
} while ( F_6 ( V_13 , & ( V_10 -> V_12 ) ) );
F_9 ( V_14 , & ( V_10 -> V_12 ) ) ;
}
static void F_15 ( struct V_9 * V_10 , struct V_18 * V_19 )
{
T_2 V_25 = * ( T_2 * ) V_19 -> V_21 ;
int V_26 ;
F_16 ( V_27 L_2 ) ;
for ( V_26 = 0 ; V_26 < V_19 -> V_4 ; V_26 ++ )
F_16 ( L_3 , V_19 -> V_21 [ V_26 ] ) ;
F_16 ( L_4 ) ;
if ( ( ( V_10 -> V_25 & 0x07 ) == 0 ) && ( ( V_25 & 0x07 ) != 0 ) ) {
F_9 ( V_11 , & ( V_10 -> V_12 ) ) ;
F_4 ( V_10 ) ;
}
V_10 -> V_25 = V_25 ;
F_12 ( V_19 ) ;
}
static void F_17 ( struct V_9 * V_10 )
{
unsigned int V_1 ;
struct V_28 * V_28 ;
int V_29 = 0 ;
if ( ! V_10 ) {
F_5 ( L_1 ) ;
return;
}
V_1 = V_10 -> V_15 -> V_16 [ 0 ] -> V_17 ;
do {
V_10 -> V_22 -> V_23 . V_30 ++ ;
if ( V_10 -> V_31 == NULL ) {
V_10 -> V_31 = F_18 ( V_32 , V_33 ) ;
if ( ! V_10 -> V_31 ) {
F_5 ( L_5 ) ;
V_10 -> V_34 = V_35 ;
V_10 -> V_36 = V_37 ;
return;
}
}
* F_19 ( V_10 -> V_31 , 1 ) = F_2 ( V_1 + V_38 ) ;
V_28 = (struct V_28 * ) V_10 -> V_31 -> V_21 ;
V_10 -> V_36 -- ;
if ( V_10 -> V_36 == 0 ) {
switch ( V_10 -> V_34 ) {
case V_35 :
V_10 -> V_34 = V_39 ;
V_10 -> V_36 = V_28 -> V_4 + ( V_28 -> V_4 & 0x0001 ) ;
break;
case V_39 :
F_20 ( V_10 -> V_31 ) = V_28 -> type ;
if ( V_28 -> V_4 & 0x0001 ) {
V_10 -> V_31 -> V_40 -- ;
V_10 -> V_31 -> V_4 -- ;
}
F_13 ( V_10 -> V_31 , V_37 ) ;
switch ( F_20 ( V_10 -> V_31 ) ) {
case 0x80 :
F_15 ( V_10 , V_10 -> V_31 ) ;
break;
case 0x82 :
case 0x83 :
case 0x84 :
F_20 ( V_10 -> V_31 ) &= 0x0f ;
F_21 ( V_10 -> V_22 , V_10 -> V_31 ) ;
break;
default:
F_5 ( L_6 ,
F_20 ( V_10 -> V_31 ) ) ;
F_12 ( V_10 -> V_31 ) ;
break;
}
V_10 -> V_34 = V_35 ;
V_10 -> V_36 = V_37 ;
V_10 -> V_31 = NULL ;
break;
}
}
if ( V_29 ++ > 32 )
break;
} while ( F_2 ( V_1 + V_6 ) & V_41 );
}
static T_3 F_22 ( int V_42 , void * V_43 )
{
struct V_9 * V_10 = V_43 ;
unsigned int V_1 ;
unsigned char V_44 ;
int V_29 = 0 ;
int V_45 , V_46 ;
T_3 V_47 = V_48 ;
if ( ! V_10 || ! V_10 -> V_22 )
return V_48 ;
V_1 = V_10 -> V_15 -> V_16 [ 0 ] -> V_17 ;
F_23 ( & ( V_10 -> V_49 ) ) ;
V_45 = F_2 ( V_1 + V_50 ) & V_51 ;
while ( V_45 ) {
V_47 = V_52 ;
V_46 = F_2 ( V_1 + V_6 ) ;
switch ( V_45 ) {
case V_53 :
F_5 ( L_7 ) ;
break;
case V_54 :
F_17 ( V_10 ) ;
break;
case V_55 :
if ( V_46 & V_7 ) {
F_4 ( V_10 ) ;
}
break;
default:
F_5 ( L_8 , V_45 ) ;
break;
}
if ( V_29 ++ > 100 )
break;
V_45 = F_2 ( V_1 + V_50 ) & V_51 ;
}
V_44 = F_2 ( V_1 + V_56 ) ;
if ( V_10 -> V_57 ^ ( V_44 & V_58 ) ) {
V_10 -> V_57 = V_44 & V_58 ;
F_9 ( V_11 , & ( V_10 -> V_12 ) ) ;
F_4 ( V_10 ) ;
V_47 = V_52 ;
}
F_24 ( & ( V_10 -> V_49 ) ) ;
return V_47 ;
}
static int F_25 ( struct V_59 * V_22 )
{
return 0 ;
}
static int F_26 ( struct V_59 * V_22 )
{
struct V_9 * V_10 = F_27 ( V_22 ) ;
F_28 ( & ( V_10 -> V_20 ) ) ;
return 0 ;
}
static int F_29 ( struct V_59 * V_22 )
{
F_26 ( V_22 ) ;
return 0 ;
}
static int F_30 ( struct V_59 * V_22 , struct V_18 * V_19 )
{
struct V_9 * V_10 = F_27 ( V_22 ) ;
struct V_18 * V_60 ;
struct V_28 V_28 ;
switch ( F_20 ( V_19 ) ) {
case V_61 :
V_22 -> V_23 . V_62 ++ ;
V_28 . type = 0x81 ;
break;
case V_63 :
V_22 -> V_23 . V_64 ++ ;
V_28 . type = 0x82 ;
break;
case V_65 :
V_22 -> V_23 . V_66 ++ ;
V_28 . type = 0x83 ;
break;
default:
return - V_67 ;
}
V_28 . V_68 = 0 ;
V_28 . V_4 = V_19 -> V_4 ;
V_60 = F_18 ( V_37 + V_19 -> V_4 + 1 , V_33 ) ;
if ( ! V_60 )
return - V_69 ;
F_31 ( V_60 , V_37 ) ;
F_32 ( V_19 , F_19 ( V_60 , V_19 -> V_4 ) , V_19 -> V_4 ) ;
if ( V_19 -> V_4 & 0x0001 )
* F_19 ( V_60 , 1 ) = 0 ;
memcpy ( F_33 ( V_60 , V_37 ) , & V_28 , V_37 ) ;
F_34 ( & ( V_10 -> V_20 ) , V_60 ) ;
F_4 ( V_10 ) ;
F_12 ( V_19 ) ;
return 0 ;
}
static int F_35 ( struct V_9 * V_10 )
{
unsigned long V_70 ;
unsigned int V_1 = V_10 -> V_15 -> V_16 [ 0 ] -> V_17 ;
struct V_59 * V_22 ;
F_36 ( & ( V_10 -> V_49 ) ) ;
F_37 ( & ( V_10 -> V_20 ) ) ;
V_10 -> V_34 = V_35 ;
V_10 -> V_36 = V_37 ;
V_10 -> V_31 = NULL ;
F_7 ( V_11 , & ( V_10 -> V_12 ) ) ;
V_22 = F_38 () ;
if ( ! V_22 ) {
F_5 ( L_9 ) ;
return - V_69 ;
}
V_10 -> V_22 = V_22 ;
V_22 -> V_71 = V_72 ;
F_39 ( V_22 , V_10 ) ;
F_40 ( V_22 , & V_10 -> V_15 -> V_73 ) ;
V_22 -> V_74 = F_25 ;
V_22 -> V_75 = F_29 ;
V_22 -> V_76 = F_26 ;
V_22 -> V_77 = F_30 ;
F_41 ( & ( V_10 -> V_49 ) , V_70 ) ;
F_3 ( 0 , V_1 + V_78 ) ;
F_3 ( 0 , V_1 + V_79 ) ;
F_3 ( V_80 , V_1 + V_81 ) ;
F_3 ( ( V_82 | V_83 | V_84 ) , V_1 + V_78 ) ;
V_10 -> V_57 = F_2 ( V_10 -> V_15 -> V_16 [ 0 ] -> V_17 + V_56 )
& V_58 ;
F_3 ( V_85 | V_86 | V_87 , V_1 + V_79 ) ;
F_42 ( & ( V_10 -> V_49 ) , V_70 ) ;
F_43 ( 2000 ) ;
if ( F_44 ( V_22 ) < 0 ) {
F_5 ( L_10 ) ;
V_10 -> V_22 = NULL ;
F_45 ( V_22 ) ;
return - V_88 ;
}
return 0 ;
}
static int F_46 ( struct V_9 * V_10 )
{
unsigned long V_70 ;
unsigned int V_1 = V_10 -> V_15 -> V_16 [ 0 ] -> V_17 ;
struct V_59 * V_22 = V_10 -> V_22 ;
if ( ! V_22 )
return - V_88 ;
F_29 ( V_22 ) ;
F_41 ( & ( V_10 -> V_49 ) , V_70 ) ;
F_3 ( 0 , V_1 + V_78 ) ;
F_3 ( 0 , V_1 + V_79 ) ;
F_42 ( & ( V_10 -> V_49 ) , V_70 ) ;
F_47 ( V_22 ) ;
F_45 ( V_22 ) ;
return 0 ;
}
static int F_48 ( struct V_89 * V_90 )
{
struct V_9 * V_10 ;
V_10 = F_49 ( & V_90 -> V_73 , sizeof( * V_10 ) , V_91 ) ;
if ( ! V_10 )
return - V_69 ;
V_10 -> V_15 = V_90 ;
V_90 -> V_92 = V_10 ;
V_90 -> V_93 |= V_94 | V_95 ;
return F_50 ( V_90 ) ;
}
static void F_51 ( struct V_89 * V_90 )
{
struct V_9 * V_10 = V_90 -> V_92 ;
F_46 ( V_10 ) ;
F_52 ( V_90 ) ;
}
static int F_53 ( struct V_89 * V_15 , void * V_96 )
{
if ( ( V_15 -> V_16 [ 1 ] -> V_97 ) || ( V_15 -> V_16 [ 1 ] -> V_97 < 8 ) )
return - V_88 ;
V_15 -> V_16 [ 0 ] -> V_70 &= ~ V_98 ;
V_15 -> V_16 [ 0 ] -> V_70 |= V_99 ;
return F_54 ( V_15 ) ;
}
static int F_50 ( struct V_89 * V_90 )
{
struct V_9 * V_10 = V_90 -> V_92 ;
int V_100 ;
V_90 -> V_16 [ 0 ] -> V_97 = 8 ;
V_100 = F_55 ( V_90 , F_53 , NULL ) ;
if ( V_100 )
goto V_101;
V_100 = F_56 ( V_90 , F_22 ) ;
if ( V_100 )
goto V_101;
V_100 = F_57 ( V_90 ) ;
if ( V_100 )
goto V_101;
V_100 = F_35 ( V_10 ) ;
if ( V_100 )
goto V_101;
return 0 ;
V_101:
F_51 ( V_90 ) ;
return V_100 ;
}
