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
V_32 -> V_34 = F_7 ( V_31 , V_23 , V_15 ) ;
return 0 ;
}
static int F_8 ( const struct V_31 * V_31 ,
unsigned int V_2 , const char * V_35 , const struct V_32 * V_1 )
{
struct V_4 * V_25 = & F_3 ( V_31 -> V_33 ) -> V_25 ;
unsigned char V_36 [ V_15 ] , V_37 [ V_15 ] ;
int error ;
error = F_1 ( V_1 -> V_1 , V_1 -> V_2 , V_36 , V_25 ) ;
if ( error )
goto V_38;
error = F_1 ( V_35 , V_2 , V_37 , V_25 ) ;
if ( error )
goto V_38;
error = memcmp ( V_36 , V_37 , V_15 ) ;
V_39:
return error ;
V_38:
error = 1 ;
if ( V_1 -> V_2 == V_2 )
error = memcmp ( V_1 -> V_1 , V_35 , V_2 ) ;
goto V_39;
}
static struct V_31 * F_9 ( struct V_16 * V_17 , struct V_31 * V_31 ,
unsigned int V_40 )
{
struct V_41 * V_42 = V_17 -> V_22 ;
struct V_18 V_19 ;
struct V_16 * V_16 ;
int V_24 ;
F_10 ( & F_3 ( V_42 ) -> V_43 ) ;
V_24 = F_2 ( V_17 , V_31 -> V_44 . V_1 , V_31 -> V_44 . V_2 , & V_19 ) ;
switch ( V_24 ) {
case - V_26 :
V_16 = NULL ;
break;
case 0 :
V_16 = F_11 ( V_42 , V_19 . V_27 , V_19 . V_45 ) ;
F_5 ( V_19 . V_30 ) ;
break;
default:
V_16 = F_12 ( V_24 ) ;
}
F_13 ( & F_3 ( V_42 ) -> V_43 ) ;
return F_14 ( V_16 , V_31 ) ;
}
static int F_15 ( struct V_16 * V_17 , const unsigned char * V_1 ,
int V_46 , int V_47 , int V_48 ,
struct V_49 * V_50 , struct V_18 * V_19 )
{
struct V_20 * V_21 = F_3 ( V_17 -> V_22 ) ;
struct V_51 V_27 ;
T_1 time , V_52 ;
int V_24 ;
memcpy ( V_27 . V_1 , V_1 , V_15 ) ;
V_27 . V_28 = V_46 ? V_53 : V_54 ;
if ( V_47 )
V_27 . V_28 |= V_29 ;
V_27 . V_55 = 0 ;
F_16 ( V_21 , V_50 , & time , & V_52 , NULL ) ;
V_27 . V_56 = V_27 . V_57 = 0 ;
V_27 . ctime = 0 ;
V_27 . V_58 = 0 ;
V_27 . time = time ;
V_27 . V_52 = V_52 ;
F_17 ( & V_27 , V_48 ) ;
V_27 . V_59 = 0 ;
V_24 = F_18 ( V_17 , & V_27 , 1 , V_19 ) ;
if ( V_24 )
return V_24 ;
V_17 -> V_60 = V_17 -> V_61 = * V_50 ;
if ( F_19 ( V_17 ) )
( void ) F_20 ( V_17 ) ;
else
F_21 ( V_17 ) ;
return 0 ;
}
static int F_22 ( struct V_16 * V_17 , struct V_31 * V_31 , T_2 V_62 ,
bool V_63 )
{
struct V_41 * V_42 = V_17 -> V_22 ;
struct V_16 * V_16 = NULL ;
struct V_18 V_19 ;
struct V_49 V_50 ;
unsigned char V_23 [ V_15 ] ;
int V_24 , V_47 ;
F_10 ( & F_3 ( V_42 ) -> V_43 ) ;
V_24 = F_1 ( V_31 -> V_44 . V_1 , V_31 -> V_44 . V_2 ,
V_23 , & F_3 ( V_42 ) -> V_25 ) ;
if ( V_24 )
goto V_39;
V_47 = ( V_31 -> V_44 . V_1 [ 0 ] == '.' ) && ( V_23 [ 0 ] != '.' ) ;
if ( ! F_4 ( V_17 , V_23 , & V_19 ) ) {
F_5 ( V_19 . V_30 ) ;
V_24 = - V_10 ;
goto V_39;
}
V_50 = V_64 ;
V_24 = F_15 ( V_17 , V_23 , 0 , V_47 , 0 , & V_50 , & V_19 ) ;
if ( V_24 )
goto V_39;
V_16 = F_11 ( V_42 , V_19 . V_27 , V_19 . V_45 ) ;
F_5 ( V_19 . V_30 ) ;
if ( F_23 ( V_16 ) ) {
V_24 = F_24 ( V_16 ) ;
goto V_39;
}
V_16 -> V_61 = V_16 -> V_65 = V_16 -> V_60 = V_50 ;
F_25 ( V_31 , V_16 ) ;
V_39:
F_13 ( & F_3 ( V_42 ) -> V_43 ) ;
if ( ! V_24 )
V_24 = F_26 ( V_42 , V_17 , V_16 ) ;
return V_24 ;
}
static int F_27 ( struct V_16 * V_17 , struct V_31 * V_31 )
{
struct V_41 * V_42 = V_17 -> V_22 ;
struct V_16 * V_16 = F_28 ( V_31 ) ;
struct V_18 V_19 ;
int V_24 ;
F_10 ( & F_3 ( V_42 ) -> V_43 ) ;
V_24 = F_29 ( V_16 ) ;
if ( V_24 )
goto V_39;
V_24 = F_2 ( V_17 , V_31 -> V_44 . V_1 , V_31 -> V_44 . V_2 , & V_19 ) ;
if ( V_24 )
goto V_39;
V_24 = F_30 ( V_17 , & V_19 ) ;
if ( V_24 )
goto V_39;
F_31 ( V_17 ) ;
F_32 ( V_16 ) ;
V_16 -> V_60 = V_64 ;
F_33 ( V_16 ) ;
V_39:
F_13 ( & F_3 ( V_42 ) -> V_43 ) ;
if ( ! V_24 )
V_24 = F_26 ( V_42 , V_17 , V_16 ) ;
return V_24 ;
}
static int F_34 ( struct V_16 * V_17 , struct V_31 * V_31 , T_2 V_62 )
{
struct V_41 * V_42 = V_17 -> V_22 ;
struct V_18 V_19 ;
struct V_16 * V_16 ;
unsigned char V_23 [ V_15 ] ;
struct V_49 V_50 ;
int V_24 , V_47 , V_48 ;
F_10 ( & F_3 ( V_42 ) -> V_43 ) ;
V_24 = F_1 ( V_31 -> V_44 . V_1 , V_31 -> V_44 . V_2 ,
V_23 , & F_3 ( V_42 ) -> V_25 ) ;
if ( V_24 )
goto V_39;
V_47 = ( V_31 -> V_44 . V_1 [ 0 ] == '.' ) && ( V_23 [ 0 ] != '.' ) ;
if ( ! F_4 ( V_17 , V_23 , & V_19 ) ) {
F_5 ( V_19 . V_30 ) ;
V_24 = - V_10 ;
goto V_39;
}
V_50 = V_64 ;
V_48 = F_35 ( V_17 , & V_50 ) ;
if ( V_48 < 0 ) {
V_24 = V_48 ;
goto V_39;
}
V_24 = F_15 ( V_17 , V_23 , 1 , V_47 , V_48 , & V_50 , & V_19 ) ;
if ( V_24 )
goto V_66;
F_36 ( V_17 ) ;
V_16 = F_11 ( V_42 , V_19 . V_27 , V_19 . V_45 ) ;
F_5 ( V_19 . V_30 ) ;
if ( F_23 ( V_16 ) ) {
V_24 = F_24 ( V_16 ) ;
goto V_39;
}
F_37 ( V_16 , 2 ) ;
V_16 -> V_61 = V_16 -> V_65 = V_16 -> V_60 = V_50 ;
F_25 ( V_31 , V_16 ) ;
F_13 ( & F_3 ( V_42 ) -> V_43 ) ;
F_26 ( V_42 , V_17 , V_16 ) ;
return 0 ;
V_66:
F_38 ( V_17 , V_48 ) ;
V_39:
F_13 ( & F_3 ( V_42 ) -> V_43 ) ;
return V_24 ;
}
static int F_39 ( struct V_16 * V_17 , struct V_31 * V_31 )
{
struct V_16 * V_16 = F_28 ( V_31 ) ;
struct V_41 * V_42 = V_16 -> V_22 ;
struct V_18 V_19 ;
int V_24 ;
F_10 ( & F_3 ( V_42 ) -> V_43 ) ;
V_24 = F_2 ( V_17 , V_31 -> V_44 . V_1 , V_31 -> V_44 . V_2 , & V_19 ) ;
if ( V_24 )
goto V_39;
V_24 = F_30 ( V_17 , & V_19 ) ;
if ( V_24 )
goto V_39;
F_32 ( V_16 ) ;
V_16 -> V_60 = V_64 ;
F_33 ( V_16 ) ;
V_39:
F_13 ( & F_3 ( V_42 ) -> V_43 ) ;
if ( ! V_24 )
V_24 = F_26 ( V_42 , V_17 , V_16 ) ;
return V_24 ;
}
static int F_40 ( struct V_16 * V_67 , unsigned char * V_68 ,
struct V_31 * V_69 ,
struct V_16 * V_70 , unsigned char * V_71 ,
struct V_31 * V_72 , int V_47 )
{
struct V_73 * V_74 ;
struct V_51 * V_75 ;
struct V_16 * V_76 , * V_77 ;
struct V_18 V_78 , V_19 ;
struct V_49 V_50 ;
T_3 V_79 ;
int V_24 , V_80 , V_46 , V_81 , V_82 = 0 ;
V_78 . V_30 = V_19 . V_30 = V_74 = NULL ;
V_76 = F_28 ( V_69 ) ;
V_77 = F_28 ( V_72 ) ;
V_24 = F_4 ( V_67 , V_68 , & V_78 ) ;
if ( V_24 ) {
V_24 = - V_83 ;
goto V_39;
}
V_46 = F_41 ( V_76 -> V_84 ) ;
V_81 = ( V_46 && V_67 != V_70 ) ;
if ( V_81 ) {
if ( F_42 ( V_76 , & V_74 , & V_75 ) ) {
V_24 = - V_83 ;
goto V_39;
}
}
V_80 = F_43 ( V_76 ) -> V_85 ;
V_24 = F_4 ( V_70 , V_71 , & V_19 ) ;
if ( ! V_24 ) {
if ( ! V_77 ) {
if ( V_19 . V_27 != V_78 . V_27 ) {
V_24 = - V_10 ;
goto V_39;
}
if ( V_47 )
F_43 ( V_76 ) -> V_85 |= V_29 ;
else
F_43 ( V_76 ) -> V_85 &= ~ V_29 ;
if ( F_19 ( V_67 ) ) {
V_24 = F_20 ( V_76 ) ;
if ( V_24 ) {
F_43 ( V_76 ) -> V_85 = V_80 ;
goto V_39;
}
} else
F_21 ( V_76 ) ;
V_67 -> V_86 ++ ;
V_67 -> V_60 = V_67 -> V_61 = V_64 ;
if ( F_19 ( V_67 ) )
( void ) F_20 ( V_67 ) ;
else
F_21 ( V_67 ) ;
goto V_39;
}
}
V_50 = V_64 ;
if ( V_77 ) {
if ( V_24 )
goto V_39;
if ( V_46 ) {
V_24 = F_29 ( V_77 ) ;
if ( V_24 )
goto V_39;
}
V_79 = F_43 ( V_77 ) -> V_45 ;
F_33 ( V_77 ) ;
} else {
V_24 = F_15 ( V_70 , V_71 , V_46 , V_47 , 0 ,
& V_50 , & V_19 ) ;
if ( V_24 )
goto V_39;
V_79 = V_19 . V_45 ;
}
V_70 -> V_86 ++ ;
F_33 ( V_76 ) ;
F_44 ( V_76 , V_79 ) ;
if ( V_47 )
F_43 ( V_76 ) -> V_85 |= V_29 ;
else
F_43 ( V_76 ) -> V_85 &= ~ V_29 ;
if ( F_19 ( V_70 ) ) {
V_24 = F_20 ( V_76 ) ;
if ( V_24 )
goto V_87;
} else
F_21 ( V_76 ) ;
if ( V_81 ) {
F_17 ( V_75 , F_43 ( V_70 ) -> V_88 ) ;
F_45 ( V_74 , V_76 ) ;
if ( F_19 ( V_70 ) ) {
V_24 = F_46 ( V_74 ) ;
if ( V_24 )
goto V_89;
}
F_31 ( V_67 ) ;
if ( ! V_77 )
F_36 ( V_70 ) ;
}
V_24 = F_30 ( V_67 , & V_78 ) ;
V_78 . V_30 = NULL ;
if ( V_24 )
goto V_89;
V_67 -> V_86 ++ ;
V_67 -> V_60 = V_67 -> V_61 = V_50 ;
if ( F_19 ( V_67 ) )
( void ) F_20 ( V_67 ) ;
else
F_21 ( V_67 ) ;
if ( V_77 ) {
F_31 ( V_77 ) ;
if ( V_46 )
F_31 ( V_77 ) ;
V_77 -> V_60 = V_50 ;
}
V_39:
F_5 ( V_19 . V_30 ) ;
F_5 ( V_74 ) ;
F_5 ( V_78 . V_30 ) ;
return V_24 ;
V_89:
V_82 = 1 ;
if ( V_81 ) {
F_17 ( V_75 , F_43 ( V_67 ) -> V_88 ) ;
F_45 ( V_74 , V_76 ) ;
V_82 |= F_46 ( V_74 ) ;
}
V_87:
F_33 ( V_76 ) ;
F_44 ( V_76 , V_78 . V_45 ) ;
F_43 ( V_76 ) -> V_85 = V_80 ;
if ( V_77 ) {
F_44 ( V_77 , V_79 ) ;
if ( V_82 )
V_82 |= F_20 ( V_77 ) ;
} else {
int V_90 = F_30 ( V_70 , & V_19 ) ;
if ( V_82 )
V_82 |= V_90 ;
V_19 . V_30 = NULL ;
}
if ( V_82 < 0 ) {
F_47 ( V_70 -> V_22 ,
L_1 ,
V_91 , V_19 . V_45 ) ;
}
goto V_39;
}
static int F_48 ( struct V_16 * V_67 , struct V_31 * V_69 ,
struct V_16 * V_70 , struct V_31 * V_72 )
{
struct V_41 * V_42 = V_67 -> V_22 ;
unsigned char V_92 [ V_15 ] , V_93 [ V_15 ] ;
int V_24 , V_47 ;
F_10 ( & F_3 ( V_42 ) -> V_43 ) ;
V_24 = F_1 ( V_69 -> V_44 . V_1 ,
V_69 -> V_44 . V_2 , V_92 ,
& F_3 ( V_67 -> V_22 ) -> V_25 ) ;
if ( V_24 )
goto V_39;
V_24 = F_1 ( V_72 -> V_44 . V_1 ,
V_72 -> V_44 . V_2 , V_93 ,
& F_3 ( V_70 -> V_22 ) -> V_25 ) ;
if ( V_24 )
goto V_39;
V_47 =
( V_72 -> V_44 . V_1 [ 0 ] == '.' ) && ( V_93 [ 0 ] != '.' ) ;
V_24 = F_40 ( V_67 , V_92 , V_69 ,
V_70 , V_93 , V_72 , V_47 ) ;
V_39:
F_13 ( & F_3 ( V_42 ) -> V_43 ) ;
if ( ! V_24 )
V_24 = F_26 ( V_42 , V_67 , V_70 ) ;
return V_24 ;
}
static void F_49 ( struct V_41 * V_42 )
{
F_3 ( V_42 ) -> V_94 = & V_95 ;
V_42 -> V_96 = & V_97 ;
V_42 -> V_98 |= V_99 ;
}
static int F_50 ( struct V_41 * V_42 , void * V_100 , int V_101 )
{
return F_51 ( V_42 , V_100 , V_101 , 0 , F_49 ) ;
}
static struct V_31 * F_52 ( struct V_102 * V_103 ,
int V_40 , const char * V_104 ,
void * V_100 )
{
return F_53 ( V_103 , V_40 , V_104 , V_100 , F_50 ) ;
}
static int T_4 F_54 ( void )
{
return F_55 ( & V_105 ) ;
}
static void T_5 F_56 ( void )
{
F_57 ( & V_105 ) ;
}
