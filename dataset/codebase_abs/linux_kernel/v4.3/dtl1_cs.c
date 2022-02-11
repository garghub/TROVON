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
F_20 ( V_10 -> V_31 ) -> V_40 = V_28 -> type ;
if ( V_28 -> V_4 & 0x0001 ) {
V_10 -> V_31 -> V_41 -- ;
V_10 -> V_31 -> V_4 -- ;
}
F_13 ( V_10 -> V_31 , V_37 ) ;
switch ( F_20 ( V_10 -> V_31 ) -> V_40 ) {
case 0x80 :
F_15 ( V_10 , V_10 -> V_31 ) ;
break;
case 0x82 :
case 0x83 :
case 0x84 :
F_20 ( V_10 -> V_31 ) -> V_40 &= 0x0f ;
F_21 ( V_10 -> V_22 , V_10 -> V_31 ) ;
break;
default:
F_5 ( L_6 , F_20 ( V_10 -> V_31 ) -> V_40 ) ;
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
} while ( F_2 ( V_1 + V_6 ) & V_42 );
}
static T_3 F_22 ( int V_43 , void * V_44 )
{
struct V_9 * V_10 = V_44 ;
unsigned int V_1 ;
unsigned char V_45 ;
int V_29 = 0 ;
int V_46 , V_47 ;
T_3 V_48 = V_49 ;
if ( ! V_10 || ! V_10 -> V_22 )
return V_49 ;
V_1 = V_10 -> V_15 -> V_16 [ 0 ] -> V_17 ;
F_23 ( & ( V_10 -> V_50 ) ) ;
V_46 = F_2 ( V_1 + V_51 ) & V_52 ;
while ( V_46 ) {
V_48 = V_53 ;
V_47 = F_2 ( V_1 + V_6 ) ;
switch ( V_46 ) {
case V_54 :
F_5 ( L_7 ) ;
break;
case V_55 :
F_17 ( V_10 ) ;
break;
case V_56 :
if ( V_47 & V_7 ) {
F_4 ( V_10 ) ;
}
break;
default:
F_5 ( L_8 , V_46 ) ;
break;
}
if ( V_29 ++ > 100 )
break;
V_46 = F_2 ( V_1 + V_51 ) & V_52 ;
}
V_45 = F_2 ( V_1 + V_57 ) ;
if ( V_10 -> V_58 ^ ( V_45 & V_59 ) ) {
V_10 -> V_58 = V_45 & V_59 ;
F_9 ( V_11 , & ( V_10 -> V_12 ) ) ;
F_4 ( V_10 ) ;
V_48 = V_53 ;
}
F_24 ( & ( V_10 -> V_50 ) ) ;
return V_48 ;
}
static int F_25 ( struct V_60 * V_22 )
{
F_7 ( V_61 , & ( V_22 -> V_62 ) ) ;
return 0 ;
}
static int F_26 ( struct V_60 * V_22 )
{
struct V_9 * V_10 = F_27 ( V_22 ) ;
F_28 ( & ( V_10 -> V_20 ) ) ;
return 0 ;
}
static int F_29 ( struct V_60 * V_22 )
{
if ( ! F_30 ( V_61 , & ( V_22 -> V_62 ) ) )
return 0 ;
F_26 ( V_22 ) ;
return 0 ;
}
static int F_31 ( struct V_60 * V_22 , struct V_18 * V_19 )
{
struct V_9 * V_10 = F_27 ( V_22 ) ;
struct V_18 * V_63 ;
struct V_28 V_28 ;
switch ( F_20 ( V_19 ) -> V_40 ) {
case V_64 :
V_22 -> V_23 . V_65 ++ ;
V_28 . type = 0x81 ;
break;
case V_66 :
V_22 -> V_23 . V_67 ++ ;
V_28 . type = 0x82 ;
break;
case V_68 :
V_22 -> V_23 . V_69 ++ ;
V_28 . type = 0x83 ;
break;
default:
return - V_70 ;
}
V_28 . V_71 = 0 ;
V_28 . V_4 = V_19 -> V_4 ;
V_63 = F_18 ( V_37 + V_19 -> V_4 + 1 , V_33 ) ;
if ( ! V_63 )
return - V_72 ;
F_32 ( V_63 , V_37 ) ;
F_33 ( V_19 , F_19 ( V_63 , V_19 -> V_4 ) , V_19 -> V_4 ) ;
if ( V_19 -> V_4 & 0x0001 )
* F_19 ( V_63 , 1 ) = 0 ;
memcpy ( F_34 ( V_63 , V_37 ) , & V_28 , V_37 ) ;
F_35 ( & ( V_10 -> V_20 ) , V_63 ) ;
F_4 ( V_10 ) ;
F_12 ( V_19 ) ;
return 0 ;
}
static int F_36 ( struct V_9 * V_10 )
{
unsigned long V_62 ;
unsigned int V_1 = V_10 -> V_15 -> V_16 [ 0 ] -> V_17 ;
struct V_60 * V_22 ;
F_37 ( & ( V_10 -> V_50 ) ) ;
F_38 ( & ( V_10 -> V_20 ) ) ;
V_10 -> V_34 = V_35 ;
V_10 -> V_36 = V_37 ;
V_10 -> V_31 = NULL ;
F_7 ( V_11 , & ( V_10 -> V_12 ) ) ;
V_22 = F_39 () ;
if ( ! V_22 ) {
F_5 ( L_9 ) ;
return - V_72 ;
}
V_10 -> V_22 = V_22 ;
V_22 -> V_73 = V_74 ;
F_40 ( V_22 , V_10 ) ;
F_41 ( V_22 , & V_10 -> V_15 -> V_75 ) ;
V_22 -> V_76 = F_25 ;
V_22 -> V_77 = F_29 ;
V_22 -> V_78 = F_26 ;
V_22 -> V_79 = F_31 ;
F_42 ( & ( V_10 -> V_50 ) , V_62 ) ;
F_3 ( 0 , V_1 + V_80 ) ;
F_3 ( 0 , V_1 + V_81 ) ;
F_3 ( V_82 , V_1 + V_83 ) ;
F_3 ( ( V_84 | V_85 | V_86 ) , V_1 + V_80 ) ;
V_10 -> V_58 = F_2 ( V_10 -> V_15 -> V_16 [ 0 ] -> V_17 + V_57 )
& V_59 ;
F_3 ( V_87 | V_88 | V_89 , V_1 + V_81 ) ;
F_43 ( & ( V_10 -> V_50 ) , V_62 ) ;
F_44 ( 2000 ) ;
if ( F_45 ( V_22 ) < 0 ) {
F_5 ( L_10 ) ;
V_10 -> V_22 = NULL ;
F_46 ( V_22 ) ;
return - V_90 ;
}
return 0 ;
}
static int F_47 ( struct V_9 * V_10 )
{
unsigned long V_62 ;
unsigned int V_1 = V_10 -> V_15 -> V_16 [ 0 ] -> V_17 ;
struct V_60 * V_22 = V_10 -> V_22 ;
if ( ! V_22 )
return - V_90 ;
F_29 ( V_22 ) ;
F_42 ( & ( V_10 -> V_50 ) , V_62 ) ;
F_3 ( 0 , V_1 + V_80 ) ;
F_3 ( 0 , V_1 + V_81 ) ;
F_43 ( & ( V_10 -> V_50 ) , V_62 ) ;
F_48 ( V_22 ) ;
F_46 ( V_22 ) ;
return 0 ;
}
static int F_49 ( struct V_91 * V_92 )
{
struct V_9 * V_10 ;
V_10 = F_50 ( & V_92 -> V_75 , sizeof( * V_10 ) , V_93 ) ;
if ( ! V_10 )
return - V_72 ;
V_10 -> V_15 = V_92 ;
V_92 -> V_94 = V_10 ;
V_92 -> V_95 |= V_96 | V_97 ;
return F_51 ( V_92 ) ;
}
static void F_52 ( struct V_91 * V_92 )
{
struct V_9 * V_10 = V_92 -> V_94 ;
F_47 ( V_10 ) ;
F_53 ( V_92 ) ;
}
static int F_54 ( struct V_91 * V_15 , void * V_98 )
{
if ( ( V_15 -> V_16 [ 1 ] -> V_99 ) || ( V_15 -> V_16 [ 1 ] -> V_99 < 8 ) )
return - V_90 ;
V_15 -> V_16 [ 0 ] -> V_62 &= ~ V_100 ;
V_15 -> V_16 [ 0 ] -> V_62 |= V_101 ;
return F_55 ( V_15 ) ;
}
static int F_51 ( struct V_91 * V_92 )
{
struct V_9 * V_10 = V_92 -> V_94 ;
int V_102 ;
V_92 -> V_16 [ 0 ] -> V_99 = 8 ;
V_102 = F_56 ( V_92 , F_54 , NULL ) ;
if ( V_102 )
goto V_103;
V_102 = F_57 ( V_92 , F_22 ) ;
if ( V_102 )
goto V_103;
V_102 = F_58 ( V_92 ) ;
if ( V_102 )
goto V_103;
V_102 = F_36 ( V_10 ) ;
if ( V_102 )
goto V_103;
return 0 ;
V_103:
F_52 ( V_92 ) ;
return V_102 ;
}
