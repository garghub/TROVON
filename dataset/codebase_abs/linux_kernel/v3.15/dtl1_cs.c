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
unsigned int V_1 = V_9 -> V_14 -> V_15 [ 0 ] -> V_16 ;
register struct V_17 * V_18 ;
int V_4 ;
F_9 ( V_12 , & ( V_9 -> V_11 ) ) ;
if ( ! F_10 ( V_9 -> V_14 ) )
return;
V_18 = F_11 ( & ( V_9 -> V_19 ) ) ;
if ( ! V_18 )
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
if ( V_9 -> V_30 == NULL ) {
V_9 -> V_30 = F_18 ( V_31 , V_32 ) ;
if ( ! V_9 -> V_30 ) {
F_5 ( L_5 ) ;
V_9 -> V_33 = V_34 ;
V_9 -> V_35 = V_36 ;
return;
}
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
F_20 ( V_9 -> V_30 ) -> V_39 &= 0x0f ;
F_21 ( V_9 -> V_21 , V_9 -> V_30 ) ;
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
} while ( F_2 ( V_1 + V_6 ) & V_41 );
}
static T_5 F_22 ( int V_42 , void * V_43 )
{
T_2 * V_9 = V_43 ;
unsigned int V_1 ;
unsigned char V_44 ;
int V_28 = 0 ;
int V_45 , V_46 ;
T_5 V_47 = V_48 ;
if ( ! V_9 || ! V_9 -> V_21 )
return V_48 ;
V_1 = V_9 -> V_14 -> V_15 [ 0 ] -> V_16 ;
F_23 ( & ( V_9 -> V_49 ) ) ;
V_45 = F_2 ( V_1 + V_50 ) & V_51 ;
while ( V_45 ) {
V_47 = V_52 ;
V_46 = F_2 ( V_1 + V_6 ) ;
switch ( V_45 ) {
case V_53 :
F_5 ( L_7 ) ;
break;
case V_54 :
F_17 ( V_9 ) ;
break;
case V_55 :
if ( V_46 & V_7 ) {
F_4 ( V_9 ) ;
}
break;
default:
F_5 ( L_8 , V_45 ) ;
break;
}
if ( V_28 ++ > 100 )
break;
V_45 = F_2 ( V_1 + V_50 ) & V_51 ;
}
V_44 = F_2 ( V_1 + V_56 ) ;
if ( V_9 -> V_57 ^ ( V_44 & V_58 ) ) {
V_9 -> V_57 = V_44 & V_58 ;
F_9 ( V_10 , & ( V_9 -> V_11 ) ) ;
F_4 ( V_9 ) ;
V_47 = V_52 ;
}
F_24 ( & ( V_9 -> V_49 ) ) ;
return V_47 ;
}
static int F_25 ( struct V_59 * V_21 )
{
F_7 ( V_60 , & ( V_21 -> V_61 ) ) ;
return 0 ;
}
static int F_26 ( struct V_59 * V_21 )
{
T_2 * V_9 = F_27 ( V_21 ) ;
F_28 ( & ( V_9 -> V_19 ) ) ;
return 0 ;
}
static int F_29 ( struct V_59 * V_21 )
{
if ( ! F_30 ( V_60 , & ( V_21 -> V_61 ) ) )
return 0 ;
F_26 ( V_21 ) ;
return 0 ;
}
static int F_31 ( struct V_59 * V_21 , struct V_17 * V_18 )
{
T_2 * V_9 = F_27 ( V_21 ) ;
struct V_17 * V_62 ;
T_4 V_27 ;
switch ( F_20 ( V_18 ) -> V_39 ) {
case V_63 :
V_21 -> V_22 . V_64 ++ ;
V_27 . type = 0x81 ;
break;
case V_65 :
V_21 -> V_22 . V_66 ++ ;
V_27 . type = 0x82 ;
break;
case V_67 :
V_21 -> V_22 . V_68 ++ ;
V_27 . type = 0x83 ;
break;
default:
return - V_69 ;
} ;
V_27 . V_70 = 0 ;
V_27 . V_4 = V_18 -> V_4 ;
V_62 = F_18 ( V_36 + V_18 -> V_4 + 1 , V_32 ) ;
if ( ! V_62 )
return - V_71 ;
F_32 ( V_62 , V_36 ) ;
F_33 ( V_18 , F_19 ( V_62 , V_18 -> V_4 ) , V_18 -> V_4 ) ;
if ( V_18 -> V_4 & 0x0001 )
* F_19 ( V_62 , 1 ) = 0 ;
memcpy ( F_34 ( V_62 , V_36 ) , & V_27 , V_36 ) ;
F_35 ( & ( V_9 -> V_19 ) , V_62 ) ;
F_4 ( V_9 ) ;
F_12 ( V_18 ) ;
return 0 ;
}
static int F_36 ( T_2 * V_9 )
{
unsigned long V_61 ;
unsigned int V_1 = V_9 -> V_14 -> V_15 [ 0 ] -> V_16 ;
struct V_59 * V_21 ;
F_37 ( & ( V_9 -> V_49 ) ) ;
F_38 ( & ( V_9 -> V_19 ) ) ;
V_9 -> V_33 = V_34 ;
V_9 -> V_35 = V_36 ;
V_9 -> V_30 = NULL ;
F_7 ( V_10 , & ( V_9 -> V_11 ) ) ;
V_21 = F_39 () ;
if ( ! V_21 ) {
F_5 ( L_9 ) ;
return - V_71 ;
}
V_9 -> V_21 = V_21 ;
V_21 -> V_72 = V_73 ;
F_40 ( V_21 , V_9 ) ;
F_41 ( V_21 , & V_9 -> V_14 -> V_74 ) ;
V_21 -> V_75 = F_25 ;
V_21 -> V_76 = F_29 ;
V_21 -> V_77 = F_26 ;
V_21 -> V_78 = F_31 ;
F_42 ( & ( V_9 -> V_49 ) , V_61 ) ;
F_3 ( 0 , V_1 + V_79 ) ;
F_3 ( 0 , V_1 + V_80 ) ;
F_3 ( V_81 , V_1 + V_82 ) ;
F_3 ( ( V_83 | V_84 | V_85 ) , V_1 + V_79 ) ;
V_9 -> V_57 = F_2 ( V_9 -> V_14 -> V_15 [ 0 ] -> V_16 + V_56 )
& V_58 ;
F_3 ( V_86 | V_87 | V_88 , V_1 + V_80 ) ;
F_43 ( & ( V_9 -> V_49 ) , V_61 ) ;
F_44 ( 2000 ) ;
if ( F_45 ( V_21 ) < 0 ) {
F_5 ( L_10 ) ;
V_9 -> V_21 = NULL ;
F_46 ( V_21 ) ;
return - V_89 ;
}
return 0 ;
}
static int F_47 ( T_2 * V_9 )
{
unsigned long V_61 ;
unsigned int V_1 = V_9 -> V_14 -> V_15 [ 0 ] -> V_16 ;
struct V_59 * V_21 = V_9 -> V_21 ;
if ( ! V_21 )
return - V_89 ;
F_29 ( V_21 ) ;
F_42 ( & ( V_9 -> V_49 ) , V_61 ) ;
F_3 ( 0 , V_1 + V_79 ) ;
F_3 ( 0 , V_1 + V_80 ) ;
F_43 ( & ( V_9 -> V_49 ) , V_61 ) ;
F_48 ( V_21 ) ;
F_46 ( V_21 ) ;
return 0 ;
}
static int F_49 ( struct V_90 * V_91 )
{
T_2 * V_9 ;
V_9 = F_50 ( & V_91 -> V_74 , sizeof( * V_9 ) , V_92 ) ;
if ( ! V_9 )
return - V_71 ;
V_9 -> V_14 = V_91 ;
V_91 -> V_93 = V_9 ;
V_91 -> V_94 |= V_95 | V_96 ;
return F_51 ( V_91 ) ;
}
static void F_52 ( struct V_90 * V_91 )
{
T_2 * V_9 = V_91 -> V_93 ;
F_47 ( V_9 ) ;
F_53 ( V_91 ) ;
}
static int F_54 ( struct V_90 * V_14 , void * V_97 )
{
if ( ( V_14 -> V_15 [ 1 ] -> V_98 ) || ( V_14 -> V_15 [ 1 ] -> V_98 < 8 ) )
return - V_89 ;
V_14 -> V_15 [ 0 ] -> V_61 &= ~ V_99 ;
V_14 -> V_15 [ 0 ] -> V_61 |= V_100 ;
return F_55 ( V_14 ) ;
}
static int F_51 ( struct V_90 * V_91 )
{
T_2 * V_9 = V_91 -> V_93 ;
int V_101 ;
V_91 -> V_15 [ 0 ] -> V_98 = 8 ;
V_101 = F_56 ( V_91 , F_54 , NULL ) ;
if ( V_101 )
goto V_102;
V_101 = F_57 ( V_91 , F_22 ) ;
if ( V_101 )
goto V_102;
V_101 = F_58 ( V_91 ) ;
if ( V_101 )
goto V_102;
V_101 = F_36 ( V_9 ) ;
if ( V_101 )
goto V_102;
return 0 ;
V_102:
F_52 ( V_91 ) ;
return V_101 ;
}
