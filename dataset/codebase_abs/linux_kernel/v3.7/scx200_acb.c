static void F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
const char * V_4 ;
F_2 ( & V_2 -> V_5 . V_6 , L_1 ,
V_7 [ V_2 -> V_8 ] , V_3 ) ;
if ( V_3 & V_9 ) {
V_4 = L_2 ;
goto error;
}
if ( ! ( V_3 & V_10 ) ) {
V_4 = L_3 ;
goto error;
}
if ( V_3 & V_11 ) {
F_2 ( & V_2 -> V_5 . V_6 , L_4 ,
V_7 [ V_2 -> V_8 ] ) ;
V_2 -> V_8 = V_12 ;
V_2 -> V_13 = - V_14 ;
F_3 ( F_4 ( V_15 ) | V_16 , V_15 ) ;
F_3 ( V_17 | V_11 , V_18 ) ;
F_3 ( 0 , V_18 ) ;
return;
}
switch ( V_2 -> V_8 ) {
case V_12 :
F_5 ( & V_2 -> V_5 . V_6 , L_5 ) ;
break;
case V_19 :
F_3 ( V_2 -> V_20 & ~ 1 , V_21 ) ;
V_2 -> V_8 = V_22 ;
break;
case V_22 :
F_3 ( V_2 -> V_23 , V_21 ) ;
if ( V_2 -> V_20 & 1 )
V_2 -> V_8 = V_24 ;
else
V_2 -> V_8 = V_25 ;
break;
case V_24 :
F_3 ( F_4 ( V_15 ) | V_26 , V_15 ) ;
case V_27 :
if ( V_2 -> V_20 & 1 ) {
if ( V_2 -> V_28 == 1 )
F_3 ( F_4 ( V_15 ) | V_29 , V_15 ) ;
else
F_3 ( F_4 ( V_15 ) & ~ V_29 , V_15 ) ;
F_3 ( V_2 -> V_20 , V_21 ) ;
V_2 -> V_8 = V_30 ;
} else {
F_3 ( V_2 -> V_20 , V_21 ) ;
V_2 -> V_8 = V_25 ;
}
break;
case V_30 :
if ( V_2 -> V_28 == 2 )
F_3 ( F_4 ( V_15 ) | V_29 , V_15 ) ;
else
F_3 ( F_4 ( V_15 ) & ~ V_29 , V_15 ) ;
if ( V_2 -> V_28 == 1 ) {
V_2 -> V_13 = 0 ;
V_2 -> V_8 = V_12 ;
F_3 ( F_4 ( V_15 ) | V_16 , V_15 ) ;
}
* V_2 -> V_31 ++ = F_4 ( V_21 ) ;
-- V_2 -> V_28 ;
break;
case V_25 :
if ( V_2 -> V_28 == 0 ) {
V_2 -> V_13 = 0 ;
V_2 -> V_8 = V_12 ;
F_3 ( F_4 ( V_15 ) | V_16 , V_15 ) ;
break;
}
F_3 ( * V_2 -> V_31 ++ , V_21 ) ;
-- V_2 -> V_28 ;
break;
}
return;
error:
F_6 ( & V_2 -> V_5 . V_6 ,
L_6 , V_4 ,
V_7 [ V_2 -> V_8 ] , V_2 -> V_20 ,
V_2 -> V_28 , V_3 ) ;
V_2 -> V_8 = V_12 ;
V_2 -> V_13 = - V_32 ;
V_2 -> V_33 = 1 ;
}
static void F_7 ( struct V_1 * V_2 )
{
T_1 V_3 ;
unsigned long V_34 ;
V_34 = V_35 + V_36 ;
while ( 1 ) {
V_3 = F_4 ( V_18 ) ;
F_3 ( 0 , V_18 ) ;
if ( ( V_3 & ( V_37 | V_9 | V_11 ) ) != 0 ) {
F_1 ( V_2 , V_3 ) ;
return;
}
if ( F_8 ( V_35 , V_34 ) )
break;
F_9 () ;
F_10 () ;
}
F_6 ( & V_2 -> V_5 . V_6 , L_7 ,
V_7 [ V_2 -> V_8 ] ) ;
V_2 -> V_8 = V_12 ;
V_2 -> V_13 = - V_32 ;
V_2 -> V_33 = 1 ;
}
static void F_11 ( struct V_1 * V_2 )
{
F_3 ( 0x70 , V_38 ) ;
F_3 ( 0 , V_15 ) ;
F_3 ( 0 , V_39 ) ;
F_3 ( F_4 ( V_38 ) | V_40 , V_38 ) ;
F_3 ( F_4 ( V_15 ) & ~ ( V_41 | V_42 ) , V_15 ) ;
F_3 ( F_4 ( V_15 ) | V_16 , V_15 ) ;
F_3 ( V_9 | V_11 | V_17 , V_18 ) ;
F_3 ( F_4 ( V_43 ) | V_44 , V_43 ) ;
}
static T_2 F_12 ( struct V_45 * V_5 ,
T_3 V_46 , unsigned short V_47 ,
char V_48 , T_1 V_23 , int V_49 ,
union V_50 * V_51 )
{
struct V_1 * V_2 = F_13 ( V_5 ) ;
int V_28 ;
T_1 * V_52 ;
T_3 V_53 ;
int V_54 ;
switch ( V_49 ) {
case V_55 :
V_28 = 0 ;
V_52 = NULL ;
break;
case V_56 :
V_28 = 1 ;
V_52 = V_48 ? & V_51 -> V_57 : & V_23 ;
break;
case V_58 :
V_28 = 1 ;
V_52 = & V_51 -> V_57 ;
break;
case V_59 :
V_28 = 2 ;
V_53 = F_14 ( V_51 -> V_60 ) ;
V_52 = ( T_1 * ) & V_53 ;
break;
case V_61 :
V_28 = V_51 -> V_62 [ 0 ] ;
if ( V_28 == 0 || V_28 > V_63 )
return - V_64 ;
V_52 = & V_51 -> V_62 [ 1 ] ;
break;
default:
return - V_64 ;
}
F_2 ( & V_5 -> V_6 ,
L_8 ,
V_49 , V_46 , V_23 , V_28 , V_48 ) ;
if ( ! V_28 && V_48 == V_65 ) {
F_2 ( & V_5 -> V_6 , L_9 ) ;
return - V_64 ;
}
F_15 ( & V_2 -> V_66 ) ;
V_2 -> V_20 = ( V_46 << 1 ) | V_48 ;
V_2 -> V_23 = V_23 ;
V_2 -> V_31 = V_52 ;
V_2 -> V_28 = V_28 ;
V_2 -> V_13 = - V_64 ;
V_2 -> V_33 = 0 ;
F_3 ( F_4 ( V_15 ) | V_26 , V_15 ) ;
if ( V_49 == V_55 || V_49 == V_56 )
V_2 -> V_8 = V_27 ;
else
V_2 -> V_8 = V_19 ;
while ( V_2 -> V_8 != V_12 )
F_7 ( V_2 ) ;
if ( V_2 -> V_33 )
F_11 ( V_2 ) ;
V_54 = V_2 -> V_13 ;
F_16 ( & V_2 -> V_66 ) ;
if ( V_54 == 0 && V_49 == V_59 && V_48 == V_65 )
V_51 -> V_60 = F_17 ( V_53 ) ;
#ifdef F_18
F_2 ( & V_5 -> V_6 , L_10 , V_54 ) ;
if ( V_52 ) {
int V_67 ;
F_19 ( L_11 ) ;
for ( V_67 = 0 ; V_67 < V_28 ; ++ V_67 )
F_19 ( L_12 , V_52 [ V_67 ] ) ;
}
F_19 ( L_13 ) ;
#endif
return V_54 ;
}
static T_4 F_20 ( struct V_45 * V_5 )
{
return V_68 | V_69 |
V_70 | V_71 |
V_72 ;
}
static T_5 int F_21 ( struct V_1 * V_2 )
{
T_1 V_73 ;
F_3 ( 0x70 , V_38 ) ;
if ( F_4 ( V_38 ) != 0x70 ) {
F_22 ( L_14 ) ;
return - V_14 ;
}
F_3 ( F_4 ( V_15 ) | V_42 , V_15 ) ;
V_73 = F_4 ( V_15 ) ;
if ( V_73 ) {
F_22 ( L_15 , V_73 ) ;
return - V_14 ;
}
F_3 ( F_4 ( V_38 ) | V_40 , V_38 ) ;
F_3 ( F_4 ( V_15 ) | V_42 , V_15 ) ;
V_73 = F_4 ( V_15 ) ;
if ( ( V_73 & V_42 ) != V_42 ) {
F_22 ( L_16 ,
V_73 ) ;
return - V_14 ;
}
return 0 ;
}
int T_5 F_23 ( struct V_1 * V_2 )
{
struct V_45 * V_5 ;
int V_54 ;
V_5 = & V_2 -> V_5 ;
V_54 = F_21 ( V_2 ) ;
if ( V_54 ) {
F_24 ( L_17 ) ;
return V_54 ;
}
F_11 ( V_2 ) ;
if ( F_25 ( V_5 ) < 0 ) {
F_26 ( L_18 ) ;
return - V_74 ;
}
if ( ! V_5 -> V_6 . V_75 ) {
F_15 ( & V_76 ) ;
V_2 -> V_77 = V_78 ;
V_78 = V_2 ;
F_16 ( & V_76 ) ;
}
return 0 ;
}
static struct V_1 * T_5 F_27 ( const char * V_79 ,
unsigned long V_80 , int V_81 , struct V_82 * V_6 )
{
struct V_1 * V_2 ;
int V_54 ;
V_2 = F_28 ( V_79 , V_6 , V_81 ) ;
if ( V_2 == NULL )
return NULL ;
if ( ! F_29 ( V_80 , 8 , V_2 -> V_5 . V_83 ) ) {
F_26 ( L_19 , V_80 , V_80 + 8 - 1 ) ;
goto V_84;
}
V_2 -> V_80 = V_80 ;
V_54 = F_23 ( V_2 ) ;
if ( V_54 == 0 )
return V_2 ;
F_30 ( V_80 , 8 ) ;
V_84:
F_31 ( V_2 ) ;
return NULL ;
}
static int T_5 F_32 ( struct V_85 * V_86 )
{
struct V_1 * V_2 ;
struct V_87 * V_88 ;
V_88 = F_33 ( V_86 , V_89 , 0 ) ;
if ( ! V_88 ) {
F_6 ( & V_86 -> V_6 , L_20 ) ;
return - V_74 ;
}
V_2 = F_27 ( L_21 , V_88 -> V_90 , 0 , & V_86 -> V_6 ) ;
if ( ! V_2 )
return - V_32 ;
F_34 ( & V_86 -> V_6 , L_22 ,
V_2 -> V_5 . V_83 ) ;
F_35 ( V_86 , V_2 ) ;
return 0 ;
}
static void T_6 F_36 ( struct V_1 * V_2 )
{
F_37 ( & V_2 -> V_5 ) ;
F_30 ( V_2 -> V_80 , 8 ) ;
F_31 ( V_2 ) ;
}
static int T_6 F_38 ( struct V_85 * V_86 )
{
struct V_1 * V_2 ;
V_2 = F_39 ( V_86 ) ;
F_35 ( V_86 , NULL ) ;
F_36 ( V_2 ) ;
return 0 ;
}
static T_7 void F_40 ( void )
{
int V_67 ;
if ( ! F_41 ( V_91 ) )
return;
for ( V_67 = 0 ; V_67 < V_92 ; ++ V_67 ) {
if ( V_80 [ V_67 ] == 0 )
continue;
F_27 ( L_23 , V_80 [ V_67 ] , V_67 , NULL ) ;
}
}
static int T_7 F_42 ( void )
{
F_22 ( L_24 ) ;
F_40 () ;
if ( V_78 )
return 0 ;
return F_43 ( & V_93 ) ;
}
static void T_8 F_44 ( void )
{
struct V_1 * V_2 ;
F_45 ( & V_93 ) ;
F_15 ( & V_76 ) ;
while ( ( V_2 = V_78 ) != NULL ) {
V_78 = V_2 -> V_77 ;
F_16 ( & V_76 ) ;
F_36 ( V_2 ) ;
F_15 ( & V_76 ) ;
}
F_16 ( & V_76 ) ;
}
