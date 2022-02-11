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
static void F_4 ( T_2 * V_9 )
{
if ( ! V_9 ) {
F_5 ( L_1 ) ;
return;
}
if ( F_6 ( V_10 , & ( V_9 -> V_11 ) ) ) {
F_7 ( V_12 , & ( V_9 -> V_11 ) ) ;
return;
}
if ( F_8 ( V_13 , & ( V_9 -> V_11 ) ) ) {
F_7 ( V_12 , & ( V_9 -> V_11 ) ) ;
return;
}
do {
register unsigned int V_1 = V_9 -> V_14 -> V_15 [ 0 ] -> V_16 ;
register struct V_17 * V_18 ;
register int V_4 ;
F_9 ( V_12 , & ( V_9 -> V_11 ) ) ;
if ( ! F_10 ( V_9 -> V_14 ) )
return;
if ( ! ( V_18 = F_11 ( & ( V_9 -> V_19 ) ) ) )
break;
V_4 = F_1 ( V_1 , 32 , V_18 -> V_20 , V_18 -> V_4 ) ;
if ( V_4 == V_18 -> V_4 ) {
F_7 ( V_10 , & ( V_9 -> V_11 ) ) ;
F_12 ( V_18 ) ;
} else {
F_13 ( V_18 , V_4 ) ;
F_14 ( & ( V_9 -> V_19 ) , V_18 ) ;
}
V_9 -> V_21 -> V_22 . V_23 += V_4 ;
} while ( F_6 ( V_12 , & ( V_9 -> V_11 ) ) );
F_9 ( V_13 , & ( V_9 -> V_11 ) ) ;
}
static void F_15 ( T_2 * V_9 , struct V_17 * V_18 )
{
T_3 V_24 = * ( T_3 * ) V_18 -> V_20 ;
int V_25 ;
F_16 ( V_26 L_2 ) ;
for ( V_25 = 0 ; V_25 < V_18 -> V_4 ; V_25 ++ ) {
F_16 ( L_3 , V_18 -> V_20 [ V_25 ] ) ;
}
F_16 ( L_4 ) ;
if ( ( ( V_9 -> V_24 & 0x07 ) == 0 ) && ( ( V_24 & 0x07 ) != 0 ) ) {
F_9 ( V_10 , & ( V_9 -> V_11 ) ) ;
F_4 ( V_9 ) ;
}
V_9 -> V_24 = V_24 ;
F_12 ( V_18 ) ;
}
static void F_17 ( T_2 * V_9 )
{
unsigned int V_1 ;
T_4 * V_27 ;
int V_28 = 0 ;
if ( ! V_9 ) {
F_5 ( L_1 ) ;
return;
}
V_1 = V_9 -> V_14 -> V_15 [ 0 ] -> V_16 ;
do {
V_9 -> V_21 -> V_22 . V_29 ++ ;
if ( V_9 -> V_30 == NULL )
if ( ! ( V_9 -> V_30 = F_18 ( V_31 , V_32 ) ) ) {
F_5 ( L_5 ) ;
V_9 -> V_33 = V_34 ;
V_9 -> V_35 = V_36 ;
return;
}
* F_19 ( V_9 -> V_30 , 1 ) = F_2 ( V_1 + V_37 ) ;
V_27 = ( T_4 * ) V_9 -> V_30 -> V_20 ;
V_9 -> V_35 -- ;
if ( V_9 -> V_35 == 0 ) {
switch ( V_9 -> V_33 ) {
case V_34 :
V_9 -> V_33 = V_38 ;
V_9 -> V_35 = V_27 -> V_4 + ( V_27 -> V_4 & 0x0001 ) ;
break;
case V_38 :
F_20 ( V_9 -> V_30 ) -> V_39 = V_27 -> type ;
if ( V_27 -> V_4 & 0x0001 ) {
V_9 -> V_30 -> V_40 -- ;
V_9 -> V_30 -> V_4 -- ;
}
F_13 ( V_9 -> V_30 , V_36 ) ;
switch ( F_20 ( V_9 -> V_30 ) -> V_39 ) {
case 0x80 :
F_15 ( V_9 , V_9 -> V_30 ) ;
break;
case 0x82 :
case 0x83 :
case 0x84 :
V_9 -> V_30 -> V_41 = ( void * ) V_9 -> V_21 ;
F_20 ( V_9 -> V_30 ) -> V_39 &= 0x0f ;
F_21 ( V_9 -> V_30 ) ;
break;
default:
F_5 ( L_6 , F_20 ( V_9 -> V_30 ) -> V_39 ) ;
F_12 ( V_9 -> V_30 ) ;
break;
}
V_9 -> V_33 = V_34 ;
V_9 -> V_35 = V_36 ;
V_9 -> V_30 = NULL ;
break;
}
}
if ( V_28 ++ > 32 )
break;
} while ( F_2 ( V_1 + V_6 ) & V_42 );
}
static T_5 F_22 ( int V_43 , void * V_44 )
{
T_2 * V_9 = V_44 ;
unsigned int V_1 ;
unsigned char V_45 ;
int V_28 = 0 ;
int V_46 , V_47 ;
T_5 V_48 = V_49 ;
if ( ! V_9 || ! V_9 -> V_21 )
return V_49 ;
V_1 = V_9 -> V_14 -> V_15 [ 0 ] -> V_16 ;
F_23 ( & ( V_9 -> V_50 ) ) ;
V_46 = F_2 ( V_1 + V_51 ) & V_52 ;
while ( V_46 ) {
V_48 = V_53 ;
V_47 = F_2 ( V_1 + V_6 ) ;
switch ( V_46 ) {
case V_54 :
F_5 ( L_7 ) ;
break;
case V_55 :
F_17 ( V_9 ) ;
break;
case V_56 :
if ( V_47 & V_7 ) {
F_4 ( V_9 ) ;
}
break;
default:
F_5 ( L_8 , V_46 ) ;
break;
}
if ( V_28 ++ > 100 )
break;
V_46 = F_2 ( V_1 + V_51 ) & V_52 ;
}
V_45 = F_2 ( V_1 + V_57 ) ;
if ( V_9 -> V_58 ^ ( V_45 & V_59 ) ) {
V_9 -> V_58 = V_45 & V_59 ;
F_9 ( V_10 , & ( V_9 -> V_11 ) ) ;
F_4 ( V_9 ) ;
V_48 = V_53 ;
}
F_24 ( & ( V_9 -> V_50 ) ) ;
return V_48 ;
}
static int F_25 ( struct V_60 * V_21 )
{
F_7 ( V_61 , & ( V_21 -> V_62 ) ) ;
return 0 ;
}
static int F_26 ( struct V_60 * V_21 )
{
T_2 * V_9 = ( T_2 * ) ( V_21 -> V_63 ) ;
F_27 ( & ( V_9 -> V_19 ) ) ;
return 0 ;
}
static int F_28 ( struct V_60 * V_21 )
{
if ( ! F_29 ( V_61 , & ( V_21 -> V_62 ) ) )
return 0 ;
F_26 ( V_21 ) ;
return 0 ;
}
static int F_30 ( struct V_17 * V_18 )
{
T_2 * V_9 ;
struct V_60 * V_21 = (struct V_60 * ) ( V_18 -> V_41 ) ;
struct V_17 * V_64 ;
T_4 V_27 ;
if ( ! V_21 ) {
F_5 ( L_9 ) ;
return - V_65 ;
}
V_9 = ( T_2 * ) ( V_21 -> V_63 ) ;
switch ( F_20 ( V_18 ) -> V_39 ) {
case V_66 :
V_21 -> V_22 . V_67 ++ ;
V_27 . type = 0x81 ;
break;
case V_68 :
V_21 -> V_22 . V_69 ++ ;
V_27 . type = 0x82 ;
break;
case V_70 :
V_21 -> V_22 . V_71 ++ ;
V_27 . type = 0x83 ;
break;
default:
return - V_72 ;
} ;
V_27 . V_73 = 0 ;
V_27 . V_4 = V_18 -> V_4 ;
V_64 = F_18 ( V_36 + V_18 -> V_4 + 1 , V_32 ) ;
if ( ! V_64 )
return - V_74 ;
F_31 ( V_64 , V_36 ) ;
F_32 ( V_18 , F_19 ( V_64 , V_18 -> V_4 ) , V_18 -> V_4 ) ;
if ( V_18 -> V_4 & 0x0001 )
* F_19 ( V_64 , 1 ) = 0 ;
memcpy ( F_33 ( V_64 , V_36 ) , & V_27 , V_36 ) ;
F_34 ( & ( V_9 -> V_19 ) , V_64 ) ;
F_4 ( V_9 ) ;
F_12 ( V_18 ) ;
return 0 ;
}
static void F_35 ( struct V_60 * V_21 )
{
}
static int F_36 ( struct V_60 * V_21 , unsigned int V_75 , unsigned long V_76 )
{
return - V_77 ;
}
static int F_37 ( T_2 * V_9 )
{
unsigned long V_62 ;
unsigned int V_1 = V_9 -> V_14 -> V_15 [ 0 ] -> V_16 ;
struct V_60 * V_21 ;
F_38 ( & ( V_9 -> V_50 ) ) ;
F_39 ( & ( V_9 -> V_19 ) ) ;
V_9 -> V_33 = V_34 ;
V_9 -> V_35 = V_36 ;
V_9 -> V_30 = NULL ;
F_7 ( V_10 , & ( V_9 -> V_11 ) ) ;
V_21 = F_40 () ;
if ( ! V_21 ) {
F_5 ( L_10 ) ;
return - V_74 ;
}
V_9 -> V_21 = V_21 ;
V_21 -> V_78 = V_79 ;
V_21 -> V_63 = V_9 ;
F_41 ( V_21 , & V_9 -> V_14 -> V_41 ) ;
V_21 -> V_80 = F_25 ;
V_21 -> V_81 = F_28 ;
V_21 -> V_82 = F_26 ;
V_21 -> V_83 = F_30 ;
V_21 -> V_84 = F_35 ;
V_21 -> V_85 = F_36 ;
V_21 -> V_86 = V_87 ;
F_42 ( & ( V_9 -> V_50 ) , V_62 ) ;
F_3 ( 0 , V_1 + V_88 ) ;
F_3 ( 0 , V_1 + V_89 ) ;
F_3 ( V_90 , V_1 + V_91 ) ;
F_3 ( ( V_92 | V_93 | V_94 ) , V_1 + V_88 ) ;
V_9 -> V_58 = F_2 ( V_9 -> V_14 -> V_15 [ 0 ] -> V_16 + V_57 )
& V_59 ;
F_3 ( V_95 | V_96 | V_97 , V_1 + V_89 ) ;
F_43 ( & ( V_9 -> V_50 ) , V_62 ) ;
F_44 ( 2000 ) ;
if ( F_45 ( V_21 ) < 0 ) {
F_5 ( L_11 ) ;
V_9 -> V_21 = NULL ;
F_46 ( V_21 ) ;
return - V_65 ;
}
return 0 ;
}
static int F_47 ( T_2 * V_9 )
{
unsigned long V_62 ;
unsigned int V_1 = V_9 -> V_14 -> V_15 [ 0 ] -> V_16 ;
struct V_60 * V_21 = V_9 -> V_21 ;
if ( ! V_21 )
return - V_65 ;
F_28 ( V_21 ) ;
F_42 ( & ( V_9 -> V_50 ) , V_62 ) ;
F_3 ( 0 , V_1 + V_88 ) ;
F_3 ( 0 , V_1 + V_89 ) ;
F_43 ( & ( V_9 -> V_50 ) , V_62 ) ;
F_48 ( V_21 ) ;
F_46 ( V_21 ) ;
return 0 ;
}
static int F_49 ( struct V_98 * V_99 )
{
T_2 * V_9 ;
V_9 = F_50 ( sizeof( * V_9 ) , V_100 ) ;
if ( ! V_9 )
return - V_74 ;
V_9 -> V_14 = V_99 ;
V_99 -> V_101 = V_9 ;
V_99 -> V_102 |= V_103 | V_104 ;
return F_51 ( V_99 ) ;
}
static void F_52 ( struct V_98 * V_99 )
{
T_2 * V_9 = V_99 -> V_101 ;
F_53 ( V_99 ) ;
F_54 ( V_9 ) ;
}
static int F_55 ( struct V_98 * V_14 , void * V_105 )
{
if ( ( V_14 -> V_15 [ 1 ] -> V_106 ) || ( V_14 -> V_15 [ 1 ] -> V_106 < 8 ) )
return - V_65 ;
V_14 -> V_15 [ 0 ] -> V_62 &= ~ V_107 ;
V_14 -> V_15 [ 0 ] -> V_62 |= V_108 ;
return F_56 ( V_14 ) ;
}
static int F_51 ( struct V_98 * V_99 )
{
T_2 * V_9 = V_99 -> V_101 ;
int V_25 ;
V_99 -> V_15 [ 0 ] -> V_106 = 8 ;
if ( F_57 ( V_99 , F_55 , NULL ) < 0 )
goto V_109;
V_25 = F_58 ( V_99 , F_22 ) ;
if ( V_25 != 0 )
goto V_109;
V_25 = F_59 ( V_99 ) ;
if ( V_25 != 0 )
goto V_109;
if ( F_37 ( V_9 ) != 0 )
goto V_109;
return 0 ;
V_109:
F_53 ( V_99 ) ;
return - V_65 ;
}
static void F_53 ( struct V_98 * V_99 )
{
T_2 * V_9 = V_99 -> V_101 ;
F_47 ( V_9 ) ;
F_60 ( V_99 ) ;
}
static int T_6 F_61 ( void )
{
return F_62 ( & V_110 ) ;
}
static void T_7 F_63 ( void )
{
F_64 ( & V_110 ) ;
}
