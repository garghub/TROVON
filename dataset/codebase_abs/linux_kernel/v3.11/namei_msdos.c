static int F_1 ( const unsigned char * V_1 , int V_2 ,
unsigned char * V_3 , struct V_4 * V_5 )
{
unsigned char * V_6 ;
unsigned char V_7 ;
int V_8 ;
if ( V_1 [ 0 ] == '.' ) {
if ( V_5 -> V_9 ) {
V_1 ++ ;
V_2 -- ;
} else
return - V_10 ;
}
V_8 = 1 ;
V_7 = 0 ;
for ( V_6 = V_3 ; V_2 && V_6 - V_3 < 8 ; V_6 ++ ) {
V_7 = * V_1 ++ ;
V_2 -- ;
if ( V_5 -> V_11 != 'r' && strchr ( V_12 , V_7 ) )
return - V_10 ;
if ( V_5 -> V_11 == 's' && strchr ( V_13 , V_7 ) )
return - V_10 ;
if ( V_7 >= 'A' && V_7 <= 'Z' && V_5 -> V_11 == 's' )
return - V_10 ;
if ( V_7 < ' ' || V_7 == ':' || V_7 == '\\' )
return - V_10 ;
if ( ( V_3 == V_6 ) && ( V_7 == 0xE5 ) )
V_7 = 0x05 ;
if ( V_7 == '.' )
break;
V_8 = ( V_7 == ' ' ) ;
* V_6 = ( ! V_5 -> V_14 && V_7 >= 'a' && V_7 <= 'z' ) ? V_7 - 32 : V_7 ;
}
if ( V_8 )
return - V_10 ;
if ( V_5 -> V_11 == 's' && V_2 && V_7 != '.' ) {
V_7 = * V_1 ++ ;
V_2 -- ;
if ( V_7 != '.' )
return - V_10 ;
}
while ( V_7 != '.' && V_2 -- )
V_7 = * V_1 ++ ;
if ( V_7 == '.' ) {
while ( V_6 - V_3 < 8 )
* V_6 ++ = ' ' ;
while ( V_2 > 0 && V_6 - V_3 < V_15 ) {
V_7 = * V_1 ++ ;
V_2 -- ;
if ( V_5 -> V_11 != 'r' && strchr ( V_12 , V_7 ) )
return - V_10 ;
if ( V_5 -> V_11 == 's' &&
strchr ( V_13 , V_7 ) )
return - V_10 ;
if ( V_7 < ' ' || V_7 == ':' || V_7 == '\\' )
return - V_10 ;
if ( V_7 == '.' ) {
if ( V_5 -> V_11 == 's' )
return - V_10 ;
break;
}
if ( V_7 >= 'A' && V_7 <= 'Z' && V_5 -> V_11 == 's' )
return - V_10 ;
V_8 = V_7 == ' ' ;
if ( ! V_5 -> V_14 && V_7 >= 'a' && V_7 <= 'z' )
* V_6 ++ = V_7 - 32 ;
else
* V_6 ++ = V_7 ;
}
if ( V_8 )
return - V_10 ;
if ( V_5 -> V_11 == 's' && V_2 )
return - V_10 ;
}
while ( V_6 - V_3 < V_15 )
* V_6 ++ = ' ' ;
return 0 ;
}
static int F_2 ( struct V_16 * V_17 , const unsigned char * V_1 , int V_2 ,
struct V_18 * V_19 )
{
struct V_20 * V_21 = F_3 ( V_17 -> V_22 ) ;
unsigned char V_23 [ V_15 ] ;
int V_24 ;
V_24 = F_1 ( V_1 , V_2 , V_23 , & V_21 -> V_25 ) ;
if ( V_24 )
return - V_26 ;
V_24 = F_4 ( V_17 , V_23 , V_19 ) ;
if ( ! V_24 && V_21 -> V_25 . V_9 ) {
if ( V_1 [ 0 ] == '.' ) {
if ( ! ( V_19 -> V_27 -> V_28 & V_29 ) )
V_24 = - V_26 ;
} else {
if ( V_19 -> V_27 -> V_28 & V_29 )
V_24 = - V_26 ;
}
if ( V_24 )
F_5 ( V_19 -> V_30 ) ;
}
return V_24 ;
}
static int F_6 ( const struct V_31 * V_31 , struct V_32 * V_32 )
{
struct V_4 * V_25 = & F_3 ( V_31 -> V_33 ) -> V_25 ;
unsigned char V_23 [ V_15 ] ;
int error ;
error = F_1 ( V_32 -> V_1 , V_32 -> V_2 , V_23 , V_25 ) ;
if ( ! error )
V_32 -> V_34 = F_7 ( V_23 , V_15 ) ;
return 0 ;
}
static int F_8 ( const struct V_31 * V_35 , const struct V_31 * V_31 ,
unsigned int V_2 , const char * V_36 , const struct V_32 * V_1 )
{
struct V_4 * V_25 = & F_3 ( V_35 -> V_33 ) -> V_25 ;
unsigned char V_37 [ V_15 ] , V_38 [ V_15 ] ;
int error ;
error = F_1 ( V_1 -> V_1 , V_1 -> V_2 , V_37 , V_25 ) ;
if ( error )
goto V_39;
error = F_1 ( V_36 , V_2 , V_38 , V_25 ) ;
if ( error )
goto V_39;
error = memcmp ( V_37 , V_38 , V_15 ) ;
V_40:
return error ;
V_39:
error = 1 ;
if ( V_1 -> V_2 == V_2 )
error = memcmp ( V_1 -> V_1 , V_36 , V_2 ) ;
goto V_40;
}
static struct V_31 * F_9 ( struct V_16 * V_17 , struct V_31 * V_31 ,
unsigned int V_41 )
{
struct V_42 * V_43 = V_17 -> V_22 ;
struct V_18 V_19 ;
struct V_16 * V_16 ;
int V_24 ;
F_10 ( & F_3 ( V_43 ) -> V_44 ) ;
V_24 = F_2 ( V_17 , V_31 -> V_45 . V_1 , V_31 -> V_45 . V_2 , & V_19 ) ;
switch ( V_24 ) {
case - V_26 :
V_16 = NULL ;
break;
case 0 :
V_16 = F_11 ( V_43 , V_19 . V_27 , V_19 . V_46 ) ;
F_5 ( V_19 . V_30 ) ;
break;
default:
V_16 = F_12 ( V_24 ) ;
}
F_13 ( & F_3 ( V_43 ) -> V_44 ) ;
return F_14 ( V_16 , V_31 ) ;
}
static int F_15 ( struct V_16 * V_17 , const unsigned char * V_1 ,
int V_47 , int V_48 , int V_49 ,
struct V_50 * V_51 , struct V_18 * V_19 )
{
struct V_20 * V_21 = F_3 ( V_17 -> V_22 ) ;
struct V_52 V_27 ;
T_1 time , V_53 ;
int V_24 ;
memcpy ( V_27 . V_1 , V_1 , V_15 ) ;
V_27 . V_28 = V_47 ? V_54 : V_55 ;
if ( V_48 )
V_27 . V_28 |= V_29 ;
V_27 . V_56 = 0 ;
F_16 ( V_21 , V_51 , & time , & V_53 , NULL ) ;
V_27 . V_57 = V_27 . V_58 = 0 ;
V_27 . ctime = 0 ;
V_27 . V_59 = 0 ;
V_27 . time = time ;
V_27 . V_53 = V_53 ;
F_17 ( & V_27 , V_49 ) ;
V_27 . V_60 = 0 ;
V_24 = F_18 ( V_17 , & V_27 , 1 , V_19 ) ;
if ( V_24 )
return V_24 ;
V_17 -> V_61 = V_17 -> V_62 = * V_51 ;
if ( F_19 ( V_17 ) )
( void ) F_20 ( V_17 ) ;
else
F_21 ( V_17 ) ;
return 0 ;
}
static int F_22 ( struct V_16 * V_17 , struct V_31 * V_31 , T_2 V_63 ,
bool V_64 )
{
struct V_42 * V_43 = V_17 -> V_22 ;
struct V_16 * V_16 = NULL ;
struct V_18 V_19 ;
struct V_50 V_51 ;
unsigned char V_23 [ V_15 ] ;
int V_24 , V_48 ;
F_10 ( & F_3 ( V_43 ) -> V_44 ) ;
V_24 = F_1 ( V_31 -> V_45 . V_1 , V_31 -> V_45 . V_2 ,
V_23 , & F_3 ( V_43 ) -> V_25 ) ;
if ( V_24 )
goto V_40;
V_48 = ( V_31 -> V_45 . V_1 [ 0 ] == '.' ) && ( V_23 [ 0 ] != '.' ) ;
if ( ! F_4 ( V_17 , V_23 , & V_19 ) ) {
F_5 ( V_19 . V_30 ) ;
V_24 = - V_10 ;
goto V_40;
}
V_51 = V_65 ;
V_24 = F_15 ( V_17 , V_23 , 0 , V_48 , 0 , & V_51 , & V_19 ) ;
if ( V_24 )
goto V_40;
V_16 = F_11 ( V_43 , V_19 . V_27 , V_19 . V_46 ) ;
F_5 ( V_19 . V_30 ) ;
if ( F_23 ( V_16 ) ) {
V_24 = F_24 ( V_16 ) ;
goto V_40;
}
V_16 -> V_62 = V_16 -> V_66 = V_16 -> V_61 = V_51 ;
F_25 ( V_31 , V_16 ) ;
V_40:
F_13 ( & F_3 ( V_43 ) -> V_44 ) ;
if ( ! V_24 )
V_24 = F_26 ( V_43 , V_17 , V_16 ) ;
return V_24 ;
}
static int F_27 ( struct V_16 * V_17 , struct V_31 * V_31 )
{
struct V_42 * V_43 = V_17 -> V_22 ;
struct V_16 * V_16 = V_31 -> V_67 ;
struct V_18 V_19 ;
int V_24 ;
F_10 ( & F_3 ( V_43 ) -> V_44 ) ;
V_24 = F_28 ( V_16 ) ;
if ( V_24 )
goto V_40;
V_24 = F_2 ( V_17 , V_31 -> V_45 . V_1 , V_31 -> V_45 . V_2 , & V_19 ) ;
if ( V_24 )
goto V_40;
V_24 = F_29 ( V_17 , & V_19 ) ;
if ( V_24 )
goto V_40;
F_30 ( V_17 ) ;
F_31 ( V_16 ) ;
V_16 -> V_61 = V_65 ;
F_32 ( V_16 ) ;
V_40:
F_13 ( & F_3 ( V_43 ) -> V_44 ) ;
if ( ! V_24 )
V_24 = F_26 ( V_43 , V_17 , V_16 ) ;
return V_24 ;
}
static int F_33 ( struct V_16 * V_17 , struct V_31 * V_31 , T_2 V_63 )
{
struct V_42 * V_43 = V_17 -> V_22 ;
struct V_18 V_19 ;
struct V_16 * V_16 ;
unsigned char V_23 [ V_15 ] ;
struct V_50 V_51 ;
int V_24 , V_48 , V_49 ;
F_10 ( & F_3 ( V_43 ) -> V_44 ) ;
V_24 = F_1 ( V_31 -> V_45 . V_1 , V_31 -> V_45 . V_2 ,
V_23 , & F_3 ( V_43 ) -> V_25 ) ;
if ( V_24 )
goto V_40;
V_48 = ( V_31 -> V_45 . V_1 [ 0 ] == '.' ) && ( V_23 [ 0 ] != '.' ) ;
if ( ! F_4 ( V_17 , V_23 , & V_19 ) ) {
F_5 ( V_19 . V_30 ) ;
V_24 = - V_10 ;
goto V_40;
}
V_51 = V_65 ;
V_49 = F_34 ( V_17 , & V_51 ) ;
if ( V_49 < 0 ) {
V_24 = V_49 ;
goto V_40;
}
V_24 = F_15 ( V_17 , V_23 , 1 , V_48 , V_49 , & V_51 , & V_19 ) ;
if ( V_24 )
goto V_68;
F_35 ( V_17 ) ;
V_16 = F_11 ( V_43 , V_19 . V_27 , V_19 . V_46 ) ;
F_5 ( V_19 . V_30 ) ;
if ( F_23 ( V_16 ) ) {
V_24 = F_24 ( V_16 ) ;
goto V_40;
}
F_36 ( V_16 , 2 ) ;
V_16 -> V_62 = V_16 -> V_66 = V_16 -> V_61 = V_51 ;
F_25 ( V_31 , V_16 ) ;
F_13 ( & F_3 ( V_43 ) -> V_44 ) ;
F_26 ( V_43 , V_17 , V_16 ) ;
return 0 ;
V_68:
F_37 ( V_17 , V_49 ) ;
V_40:
F_13 ( & F_3 ( V_43 ) -> V_44 ) ;
return V_24 ;
}
static int F_38 ( struct V_16 * V_17 , struct V_31 * V_31 )
{
struct V_16 * V_16 = V_31 -> V_67 ;
struct V_42 * V_43 = V_16 -> V_22 ;
struct V_18 V_19 ;
int V_24 ;
F_10 ( & F_3 ( V_43 ) -> V_44 ) ;
V_24 = F_2 ( V_17 , V_31 -> V_45 . V_1 , V_31 -> V_45 . V_2 , & V_19 ) ;
if ( V_24 )
goto V_40;
V_24 = F_29 ( V_17 , & V_19 ) ;
if ( V_24 )
goto V_40;
F_31 ( V_16 ) ;
V_16 -> V_61 = V_65 ;
F_32 ( V_16 ) ;
V_40:
F_13 ( & F_3 ( V_43 ) -> V_44 ) ;
if ( ! V_24 )
V_24 = F_26 ( V_43 , V_17 , V_16 ) ;
return V_24 ;
}
static int F_39 ( struct V_16 * V_69 , unsigned char * V_70 ,
struct V_31 * V_71 ,
struct V_16 * V_72 , unsigned char * V_73 ,
struct V_31 * V_74 , int V_48 )
{
struct V_75 * V_76 ;
struct V_52 * V_77 ;
struct V_16 * V_78 , * V_79 ;
struct V_18 V_80 , V_19 ;
struct V_50 V_51 ;
T_3 V_81 ;
int V_24 , V_82 , V_47 , V_83 , V_84 = 0 ;
V_80 . V_30 = V_19 . V_30 = V_76 = NULL ;
V_78 = V_71 -> V_67 ;
V_79 = V_74 -> V_67 ;
V_24 = F_4 ( V_69 , V_70 , & V_80 ) ;
if ( V_24 ) {
V_24 = - V_85 ;
goto V_40;
}
V_47 = F_40 ( V_78 -> V_86 ) ;
V_83 = ( V_47 && V_69 != V_72 ) ;
if ( V_83 ) {
if ( F_41 ( V_78 , & V_76 , & V_77 ) ) {
V_24 = - V_85 ;
goto V_40;
}
}
V_82 = F_42 ( V_78 ) -> V_87 ;
V_24 = F_4 ( V_72 , V_73 , & V_19 ) ;
if ( ! V_24 ) {
if ( ! V_79 ) {
if ( V_19 . V_27 != V_80 . V_27 ) {
V_24 = - V_10 ;
goto V_40;
}
if ( V_48 )
F_42 ( V_78 ) -> V_87 |= V_29 ;
else
F_42 ( V_78 ) -> V_87 &= ~ V_29 ;
if ( F_19 ( V_69 ) ) {
V_24 = F_20 ( V_78 ) ;
if ( V_24 ) {
F_42 ( V_78 ) -> V_87 = V_82 ;
goto V_40;
}
} else
F_21 ( V_78 ) ;
V_69 -> V_88 ++ ;
V_69 -> V_61 = V_69 -> V_62 = V_65 ;
if ( F_19 ( V_69 ) )
( void ) F_20 ( V_69 ) ;
else
F_21 ( V_69 ) ;
goto V_40;
}
}
V_51 = V_65 ;
if ( V_79 ) {
if ( V_24 )
goto V_40;
if ( V_47 ) {
V_24 = F_28 ( V_79 ) ;
if ( V_24 )
goto V_40;
}
V_81 = F_42 ( V_79 ) -> V_46 ;
F_32 ( V_79 ) ;
} else {
V_24 = F_15 ( V_72 , V_73 , V_47 , V_48 , 0 ,
& V_51 , & V_19 ) ;
if ( V_24 )
goto V_40;
V_81 = V_19 . V_46 ;
}
V_72 -> V_88 ++ ;
F_32 ( V_78 ) ;
F_43 ( V_78 , V_81 ) ;
if ( V_48 )
F_42 ( V_78 ) -> V_87 |= V_29 ;
else
F_42 ( V_78 ) -> V_87 &= ~ V_29 ;
if ( F_19 ( V_72 ) ) {
V_24 = F_20 ( V_78 ) ;
if ( V_24 )
goto V_89;
} else
F_21 ( V_78 ) ;
if ( V_83 ) {
F_17 ( V_77 , F_42 ( V_72 ) -> V_90 ) ;
F_44 ( V_76 , V_78 ) ;
if ( F_19 ( V_72 ) ) {
V_24 = F_45 ( V_76 ) ;
if ( V_24 )
goto V_91;
}
F_30 ( V_69 ) ;
if ( ! V_79 )
F_35 ( V_72 ) ;
}
V_24 = F_29 ( V_69 , & V_80 ) ;
V_80 . V_30 = NULL ;
if ( V_24 )
goto V_91;
V_69 -> V_88 ++ ;
V_69 -> V_61 = V_69 -> V_62 = V_51 ;
if ( F_19 ( V_69 ) )
( void ) F_20 ( V_69 ) ;
else
F_21 ( V_69 ) ;
if ( V_79 ) {
F_30 ( V_79 ) ;
if ( V_47 )
F_30 ( V_79 ) ;
V_79 -> V_61 = V_51 ;
}
V_40:
F_5 ( V_19 . V_30 ) ;
F_5 ( V_76 ) ;
F_5 ( V_80 . V_30 ) ;
return V_24 ;
V_91:
V_84 = 1 ;
if ( V_83 ) {
F_17 ( V_77 , F_42 ( V_69 ) -> V_90 ) ;
F_44 ( V_76 , V_78 ) ;
V_84 |= F_45 ( V_76 ) ;
}
V_89:
F_32 ( V_78 ) ;
F_43 ( V_78 , V_80 . V_46 ) ;
F_42 ( V_78 ) -> V_87 = V_82 ;
if ( V_79 ) {
F_43 ( V_79 , V_81 ) ;
if ( V_84 )
V_84 |= F_20 ( V_79 ) ;
} else {
int V_92 = F_29 ( V_72 , & V_19 ) ;
if ( V_84 )
V_84 |= V_92 ;
V_19 . V_30 = NULL ;
}
if ( V_84 < 0 ) {
F_46 ( V_72 -> V_22 ,
L_1 ,
V_93 , V_19 . V_46 ) ;
}
goto V_40;
}
static int F_47 ( struct V_16 * V_69 , struct V_31 * V_71 ,
struct V_16 * V_72 , struct V_31 * V_74 )
{
struct V_42 * V_43 = V_69 -> V_22 ;
unsigned char V_94 [ V_15 ] , V_95 [ V_15 ] ;
int V_24 , V_48 ;
F_10 ( & F_3 ( V_43 ) -> V_44 ) ;
V_24 = F_1 ( V_71 -> V_45 . V_1 ,
V_71 -> V_45 . V_2 , V_94 ,
& F_3 ( V_69 -> V_22 ) -> V_25 ) ;
if ( V_24 )
goto V_40;
V_24 = F_1 ( V_74 -> V_45 . V_1 ,
V_74 -> V_45 . V_2 , V_95 ,
& F_3 ( V_72 -> V_22 ) -> V_25 ) ;
if ( V_24 )
goto V_40;
V_48 =
( V_74 -> V_45 . V_1 [ 0 ] == '.' ) && ( V_95 [ 0 ] != '.' ) ;
V_24 = F_39 ( V_69 , V_94 , V_71 ,
V_72 , V_95 , V_74 , V_48 ) ;
V_40:
F_13 ( & F_3 ( V_43 ) -> V_44 ) ;
if ( ! V_24 )
V_24 = F_26 ( V_43 , V_69 , V_72 ) ;
return V_24 ;
}
static void F_48 ( struct V_42 * V_43 )
{
F_3 ( V_43 ) -> V_96 = & V_97 ;
V_43 -> V_98 = & V_99 ;
V_43 -> V_100 |= V_101 ;
}
static int F_49 ( struct V_42 * V_43 , void * V_102 , int V_103 )
{
return F_50 ( V_43 , V_102 , V_103 , 0 , F_48 ) ;
}
static struct V_31 * F_51 ( struct V_104 * V_105 ,
int V_41 , const char * V_106 ,
void * V_102 )
{
return F_52 ( V_105 , V_41 , V_106 , V_102 , F_49 ) ;
}
static int T_4 F_53 ( void )
{
return F_54 ( & V_107 ) ;
}
static void T_5 F_55 ( void )
{
F_56 ( & V_107 ) ;
}
