static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
F_2 ( L_1 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
if ( ! F_3 () )
F_4 ( V_2 -> V_5 . V_6 [ V_3 ] ) ;
else
F_5 ( V_2 -> V_5 . V_6 [ V_3 ] ) ;
F_6 ( V_2 -> V_5 . V_6 [ V_3 ] ) ;
V_2 -> V_5 . V_6 [ V_3 ] = NULL ;
F_7 ( V_2 -> V_5 . V_7 [ V_3 ] ) ;
V_2 -> V_5 . V_7 [ V_3 ] = NULL ;
}
return 0 ;
}
static void F_8 ( struct V_6 * V_6 )
{
struct V_1 * V_2 = V_6 -> V_8 ;
int V_3 ;
unsigned int V_9 ;
int V_10 = 0 ;
int V_11 ;
unsigned char * V_12 ;
unsigned int V_13 ;
struct V_14 * V_15 ;
struct V_16 * V_17 ;
switch ( V_6 -> V_11 ) {
case 0 :
case - V_18 :
break;
case - V_19 :
case - V_20 :
case - V_21 :
return;
default:
F_2 ( L_2 , V_6 -> V_11 ) ;
break;
}
if ( F_9 ( & V_2 -> V_22 ) == 0 )
return;
if ( V_2 -> V_5 . V_23 ) {
V_15 = V_2 -> V_5 . V_23 ;
V_17 = V_15 -> V_17 ;
V_13 = V_17 -> V_24 >> 3 ;
for ( V_3 = 0 ; V_3 < V_6 -> V_25 ; V_3 ++ ) {
int V_26 =
V_6 -> V_27 [ V_3 ] . V_28 / V_13 ;
V_12 = ( unsigned char * ) V_6 -> V_7 +
V_6 -> V_27 [ V_3 ] . V_29 ;
if ( ! V_26 )
continue;
V_9 = V_2 -> V_5 . V_30 ;
if ( V_9 + V_26 >= V_17 -> V_31 ) {
unsigned int V_32 =
V_17 -> V_31 - V_9 ;
memcpy ( V_17 -> V_33 + V_9 * V_13 , V_12 ,
V_32 * V_13 ) ;
memcpy ( V_17 -> V_33 , V_12 + V_32 * V_13 ,
V_26 * V_13 - V_32 * V_13 ) ;
} else {
memcpy ( V_17 -> V_33 + V_9 * V_13 , V_12 ,
V_26 * V_13 ) ;
}
F_10 ( V_15 ) ;
V_2 -> V_5 . V_30 += V_26 ;
if ( V_2 -> V_5 . V_30 >=
V_17 -> V_31 )
V_2 -> V_5 . V_30 -=
V_17 -> V_31 ;
V_2 -> V_5 . V_34 += V_26 ;
if ( V_2 -> V_5 . V_34 >=
V_17 -> V_35 ) {
V_2 -> V_5 . V_34 -=
V_17 -> V_35 ;
V_10 = 1 ;
}
F_11 ( V_15 ) ;
}
if ( V_10 )
F_12 ( V_15 ) ;
}
V_6 -> V_11 = 0 ;
V_11 = F_13 ( V_6 , V_36 ) ;
if ( V_11 < 0 ) {
F_14 ( L_3 ,
V_11 ) ;
}
return;
}
static int F_15 ( struct V_1 * V_2 )
{
int V_3 , V_37 ;
const int V_38 = V_39 *
V_40 ;
F_2 ( L_4 ) ;
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
struct V_6 * V_6 ;
int V_41 , V_42 ;
V_2 -> V_5 . V_7 [ V_3 ] = F_16 ( V_38 , V_36 ) ;
if ( ! V_2 -> V_5 . V_7 [ V_3 ] )
return - V_43 ;
memset ( V_2 -> V_5 . V_7 [ V_3 ] , 0x80 , V_38 ) ;
V_6 = F_17 ( V_39 , V_36 ) ;
if ( ! V_6 ) {
F_14 ( L_5 ) ;
for ( V_41 = 0 ; V_41 < V_3 ; V_41 ++ ) {
F_6 ( V_2 -> V_5 . V_6 [ V_41 ] ) ;
F_7 ( V_2 -> V_5 . V_7 [ V_41 ] ) ;
}
return - V_43 ;
}
V_6 -> V_2 = V_2 -> V_44 ;
V_6 -> V_8 = V_2 ;
V_6 -> V_45 = F_18 ( V_2 -> V_44 , 0x83 ) ;
V_6 -> V_46 = V_47 ;
V_6 -> V_7 = V_2 -> V_5 . V_7 [ V_3 ] ;
V_6 -> V_48 = 1 ;
V_6 -> V_49 = F_8 ;
V_6 -> V_25 = V_39 ;
V_6 -> V_50 = V_38 ;
for ( V_41 = V_42 = 0 ; V_41 < V_39 ;
V_41 ++ , V_42 += V_40 ) {
V_6 -> V_27 [ V_41 ] . V_29 = V_42 ;
V_6 -> V_27 [ V_41 ] . V_26 =
V_40 ;
}
V_2 -> V_5 . V_6 [ V_3 ] = V_6 ;
}
for ( V_3 = 0 ; V_3 < V_4 ; V_3 ++ ) {
V_37 = F_13 ( V_2 -> V_5 . V_6 [ V_3 ] , V_36 ) ;
if ( V_37 ) {
F_1 ( V_2 ) ;
return V_37 ;
}
}
return 0 ;
}
static int F_19 ( struct V_14 * V_51 ,
T_1 V_52 )
{
struct V_16 * V_17 = V_51 -> V_17 ;
F_2 ( L_6 ) ;
if ( V_17 -> V_33 ) {
if ( V_17 -> V_53 > V_52 )
return 0 ;
F_20 ( V_17 -> V_33 ) ;
}
V_17 -> V_33 = F_21 ( V_52 ) ;
if ( ! V_17 -> V_33 )
return - V_43 ;
V_17 -> V_53 = V_52 ;
return 0 ;
}
static int F_22 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_23 ( V_15 ) ;
struct V_16 * V_17 = V_15 -> V_17 ;
int V_54 = 0 ;
F_2 ( L_7 ) ;
if ( ! V_2 ) {
F_24 ( L_8
L_9 ) ;
return - V_55 ;
}
V_2 -> V_56 = 0 ;
F_25 ( & V_2 -> V_57 ) ;
V_54 = F_26 ( V_2 ) ;
if ( V_54 < 0 )
goto V_58;
V_17 -> V_59 = V_60 ;
if ( V_2 -> V_61 == 0 && V_2 -> V_5 . V_62 == 0 ) {
int V_37 ;
V_2 -> V_61 = 7 ;
F_2 ( L_10 ) ;
V_37 = F_27 ( V_2 -> V_44 , 0 , 7 ) ;
}
V_2 -> V_5 . V_62 ++ ;
F_28 ( & V_2 -> V_57 ) ;
F_29 ( V_17 , V_63 ) ;
V_2 -> V_5 . V_23 = V_15 ;
V_17 -> V_64 = V_2 ;
return 0 ;
V_58:
F_28 ( & V_2 -> V_57 ) ;
F_24 ( L_11 ) ;
return V_54 ;
}
static int F_30 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_23 ( V_15 ) ;
F_2 ( L_12 ) ;
V_2 -> V_56 = 1 ;
F_25 ( & V_2 -> V_57 ) ;
V_2 -> V_5 . V_62 -- ;
if ( F_9 ( & V_2 -> V_22 ) > 0 ) {
F_31 ( & V_2 -> V_22 , 0 ) ;
F_32 ( & V_2 -> V_65 ) ;
}
F_26 ( V_2 ) ;
if ( V_15 -> V_17 -> V_33 ) {
F_2 ( L_13 ) ;
F_20 ( V_15 -> V_17 -> V_33 ) ;
V_15 -> V_17 -> V_33 = NULL ;
}
F_28 ( & V_2 -> V_57 ) ;
return 0 ;
}
static int F_33 ( struct V_14 * V_15 ,
struct V_66 * V_67 )
{
unsigned int V_68 , V_69 , V_70 ;
int V_54 ;
F_2 ( L_14 ) ;
V_54 = F_19 ( V_15 ,
F_34 ( V_67 ) ) ;
V_70 = F_35 ( V_67 ) ;
V_69 = F_36 ( V_67 ) ;
V_68 = F_37 ( V_67 ) ;
return 0 ;
}
static int F_38 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_23 ( V_15 ) ;
F_2 ( L_15 ) ;
if ( F_9 ( & V_2 -> V_22 ) > 0 ) {
F_31 ( & V_2 -> V_22 , 0 ) ;
F_32 ( & V_2 -> V_65 ) ;
}
return 0 ;
}
static int F_39 ( struct V_14 * V_15 )
{
struct V_1 * V_2 = F_23 ( V_15 ) ;
V_2 -> V_5 . V_30 = 0 ;
V_2 -> V_5 . V_34 = 0 ;
return 0 ;
}
static void F_40 ( struct V_71 * V_72 )
{
struct V_1 * V_2 = F_41 ( V_72 , struct V_1 , V_65 ) ;
if ( F_9 ( & V_2 -> V_22 ) ) {
F_2 ( L_16 ) ;
F_15 ( V_2 ) ;
} else {
F_2 ( L_17 ) ;
F_1 ( V_2 ) ;
}
}
static int F_42 ( struct V_14 * V_15 ,
int V_73 )
{
struct V_1 * V_2 = F_23 ( V_15 ) ;
int V_74 ;
switch ( V_73 ) {
case V_75 :
F_31 ( & V_2 -> V_22 , 1 ) ;
break;
case V_76 :
F_31 ( & V_2 -> V_22 , 1 ) ;
break;
default:
V_74 = - V_77 ;
}
F_32 ( & V_2 -> V_65 ) ;
return 0 ;
}
static T_2 F_43 ( struct V_14
* V_15 )
{
unsigned long V_78 ;
struct V_1 * V_2 ;
T_2 V_79 ;
V_2 = F_23 ( V_15 ) ;
F_44 ( & V_2 -> V_5 . V_80 , V_78 ) ;
V_79 = V_2 -> V_5 . V_30 ;
F_45 ( & V_2 -> V_5 . V_80 , V_78 ) ;
return V_79 ;
}
static struct V_81 * F_46 ( struct V_14 * V_51 ,
unsigned long V_29 )
{
void * V_82 = V_51 -> V_17 -> V_33 + V_29 ;
return F_47 ( V_82 ) ;
}
static int F_48 ( struct V_1 * V_2 )
{
struct V_83 * V_5 = & V_2 -> V_5 ;
struct V_84 * V_85 ;
struct V_86 * V_87 ;
static int V_88 ;
int V_58 ;
if ( V_2 -> V_89 != 1 ) {
return 0 ;
}
F_49 ( V_90 L_18
L_19 ) ;
F_49 ( V_90 L_20
L_21 ) ;
V_58 = F_50 ( V_91 [ V_88 ] , L_22 , V_92 , 0 ,
& V_87 ) ;
if ( V_58 < 0 )
return V_58 ;
F_51 ( & V_5 -> V_80 ) ;
V_58 = F_52 ( V_87 , L_22 , 0 , 0 , 1 , & V_85 ) ;
if ( V_58 < 0 ) {
F_53 ( V_87 ) ;
return V_58 ;
}
F_54 ( V_85 , V_93 , & V_94 ) ;
V_85 -> V_95 = 0 ;
V_85 -> V_64 = V_2 ;
strcpy ( V_85 -> V_96 , L_23 ) ;
F_55 ( V_87 , & V_2 -> V_44 -> V_2 ) ;
strcpy ( V_87 -> V_97 , L_24 ) ;
strcpy ( V_87 -> V_98 , L_22 ) ;
strcpy ( V_87 -> V_99 , L_25 ) ;
F_56 ( & V_2 -> V_65 , F_40 ) ;
V_58 = F_57 ( V_87 ) ;
if ( V_58 < 0 ) {
F_53 ( V_87 ) ;
return V_58 ;
}
V_5 -> V_100 = V_87 ;
V_5 -> V_44 = V_2 -> V_44 ;
return 0 ;
}
static int F_58 ( struct V_1 * V_2 )
{
if ( V_2 == NULL )
return 0 ;
if ( V_2 -> V_89 != 1 ) {
return 0 ;
}
if ( V_2 -> V_5 . V_100 ) {
F_53 ( V_2 -> V_5 . V_100 ) ;
V_2 -> V_5 . V_100 = NULL ;
}
return 0 ;
}
static int T_3 F_59 ( void )
{
return F_60 ( & V_101 ) ;
}
static void T_4 F_61 ( void )
{
F_62 ( & V_101 ) ;
}
