static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
int V_5 = V_1 -> V_5 ;
if ( V_5 ) {
F_2 ( L_1 , V_6 , V_5 ) ;
F_3 ( & V_3 -> V_7 ) ;
return;
}
}
static void F_4 ( struct V_8 * V_8 )
{
struct V_2 * V_3 = F_5 ( V_8 ) ;
F_6 ( L_2 ) ;
F_7 ( V_3 -> V_9 ) ;
if ( V_3 -> V_10 ) {
F_8 ( V_3 -> V_10 ) ;
if ( V_3 -> V_11 )
F_9 ( V_3 -> V_9 , V_12 ,
V_3 -> V_11 , V_3 -> V_10 -> V_13 ) ;
if ( V_3 -> V_14 )
F_9 ( V_3 -> V_9 , V_12 ,
V_3 -> V_14 , V_3 -> V_10 -> V_15 ) ;
F_10 ( V_3 -> V_10 ) ;
}
if ( V_3 -> V_1 ) {
F_8 ( V_3 -> V_1 ) ;
if ( V_3 -> V_16 )
F_9 ( V_3 -> V_9 , V_12 ,
V_3 -> V_16 , V_3 -> V_1 -> V_15 ) ;
F_10 ( V_3 -> V_1 ) ;
}
F_11 ( V_3 ) ;
}
static void F_12 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
unsigned char * V_17 = V_3 -> V_16 ;
int V_5 = V_1 -> V_5 ;
unsigned long V_18 ;
int V_19 , V_20 ;
switch ( V_5 ) {
case 0 :
break;
case - V_21 :
F_2 ( L_3 ,
V_6 , V_12 , V_3 -> V_1 -> V_22 ) ;
case - V_23 :
case - V_24 :
case - V_25 :
case - V_26 :
return;
default:
F_2 ( L_4 , V_6 , V_5 ) ;
goto exit;
}
switch ( V_17 [ 0 ] ) {
case V_27 :
case V_28 :
if ( V_17 [ 6 ] == V_29 ) {
F_13 ( & V_3 -> V_30 , V_18 ) ;
V_3 -> V_31 = 0 ;
for ( V_20 = 1 ; V_20 < 6 ; V_20 ++ ) {
V_3 -> V_31 += V_17 [ V_20 ] ;
if ( V_20 != 5 )
V_3 -> V_31 <<= 8 ;
}
F_6 ( L_5 , V_6 , V_3 -> V_31 ) ;
F_14 ( & V_3 -> V_30 , V_18 ) ;
F_15 ( & V_3 -> V_32 , V_33 , V_34 ) ;
}
else
F_6 ( L_6 ) ;
break;
case V_35 :
F_6 ( L_7 , V_6 , V_17 [ 1 ] ) ;
F_3 ( & V_3 -> V_7 ) ;
break;
}
exit:
V_19 = F_16 ( V_3 -> V_1 , V_36 ) ;
if ( V_19 ) {
F_2 ( L_8 ,
V_6 , V_19 ) ;
}
}
static int F_17 ( struct V_37 * V_38 , const struct V_39 * V_40 )
{
struct V_2 * V_3 ;
struct V_41 * V_42 ;
struct V_43 * V_44 ;
int V_19 = - V_45 ;
int V_20 ;
F_18 ( V_46 ) ;
V_3 = F_19 ( sizeof( * V_3 ) , V_47 ) ;
if ( ! V_3 ) {
F_2 ( L_9 ) ;
goto error;
}
F_20 ( & V_3 -> V_8 ) ;
F_21 ( & V_3 -> V_48 ) ;
F_22 ( & V_3 -> V_30 ) ;
F_23 ( & V_3 -> V_7 ) ;
V_3 -> V_9 = F_24 ( F_25 ( V_38 ) ) ;
V_3 -> V_38 = V_38 ;
V_42 = V_38 -> V_49 ;
for ( V_20 = 0 ; V_20 < V_42 -> V_50 . V_51 ; V_20 ++ ) {
V_44 = & V_42 -> V_44 [ V_20 ] . V_50 ;
if ( F_26 ( V_44 ) ) {
V_3 -> V_52 = V_44 -> V_53 ;
break;
}
}
if ( ! V_3 -> V_52 ) {
V_19 = - V_54 ;
F_2 ( L_10 ) ;
goto error;
}
V_3 -> V_10 = F_27 ( 0 , V_47 ) ;
if ( ! V_3 -> V_10 ) {
F_2 ( L_11 ) ;
goto error;
}
V_3 -> V_11 = F_28 ( V_3 -> V_9 , V_12 ,
V_47 ,
& V_3 -> V_10 -> V_13 ) ;
if ( ! V_3 -> V_11 ) {
F_2 ( L_12 ) ;
goto error;
}
V_3 -> V_14 = F_28 ( V_3 -> V_9 , V_12 ,
V_47 ,
& V_3 -> V_10 -> V_15 ) ;
if ( ! V_3 -> V_14 ) {
F_2 ( L_13 ) ;
goto error;
}
V_3 -> V_11 -> V_55 = V_56 | V_57 |
V_58 ;
V_3 -> V_11 -> V_59 = V_60 ;
V_3 -> V_11 -> V_61 = F_29 ( ( V_62 + 1 ) << 8 ) ;
V_3 -> V_11 -> V_63 = F_29 ( V_42 -> V_50 . V_64 ) ;
V_3 -> V_11 -> V_65 = F_29 ( V_12 ) ;
F_30 ( V_3 -> V_10 , V_3 -> V_9 ,
F_31 ( V_3 -> V_9 , 0 ) ,
( void * ) V_3 -> V_11 , V_3 -> V_14 ,
V_12 , F_1 , V_3 ) ;
V_3 -> V_10 -> V_66 |= V_67 ;
V_3 -> V_1 = F_27 ( 0 , V_47 ) ;
if ( ! V_3 -> V_1 ) {
F_2 ( L_14 ) ;
goto error;
}
V_3 -> V_16 = F_28 ( V_3 -> V_9 , V_12 ,
V_47 , & V_3 -> V_1 -> V_15 ) ;
if ( ! V_3 -> V_16 ) {
F_2 ( L_15 ) ;
goto error;
}
F_32 ( V_3 -> V_1 , V_3 -> V_9 ,
F_33 ( V_3 -> V_9 , V_3 -> V_52 ) ,
V_3 -> V_16 , V_12 , F_12 ,
V_3 , 1 ) ;
V_3 -> V_10 -> V_66 |= V_67 ;
if ( F_16 ( V_3 -> V_1 , V_47 ) ) {
V_19 = - V_68 ;
F_2 ( L_16 ) ;
goto error;
}
F_34 ( V_38 , V_3 ) ;
V_19 = F_35 ( V_38 , & V_69 ) ;
if ( V_19 ) {
F_2 ( L_17 ) ;
F_34 ( V_38 , NULL ) ;
goto error;
}
V_3 -> V_31 = - 1 ;
F_36 ( & V_38 -> V_3 ,
L_18 ,
V_38 -> V_70 ) ;
return 0 ;
error:
if ( V_3 )
F_37 ( & V_3 -> V_8 , F_4 ) ;
return V_19 ;
}
static void F_38 ( struct V_37 * V_38 )
{
struct V_2 * V_3 ;
int V_70 = V_38 -> V_70 ;
V_3 = F_39 ( V_38 ) ;
F_34 ( V_38 , NULL ) ;
F_40 ( V_38 , & V_69 ) ;
F_41 ( & V_3 -> V_48 ) ;
V_3 -> V_38 = NULL ;
F_42 ( & V_3 -> V_48 ) ;
F_15 ( & V_3 -> V_32 , V_33 , V_34 ) ;
F_3 ( & V_3 -> V_7 ) ;
F_37 ( & V_3 -> V_8 , F_4 ) ;
F_36 ( & V_38 -> V_3 , L_19 , V_70 ) ;
}
static int F_43 ( int V_71 , struct V_72 * V_72 , int V_73 )
{
struct V_2 * V_3 ;
V_3 = (struct V_2 * ) V_72 -> V_74 ;
return F_44 ( V_71 , V_72 , V_73 , & V_3 -> V_32 ) ;
}
static int F_45 ( struct V_75 * V_75 , struct V_72 * V_72 )
{
struct V_2 * V_3 ;
struct V_37 * V_38 ;
int V_76 ;
int V_19 = 0 ;
V_76 = F_46 ( V_75 ) ;
V_38 = F_47 ( & V_77 , V_76 ) ;
if ( ! V_38 ) {
F_2 ( L_20 ,
V_6 , V_76 ) ;
V_19 = - V_54 ;
goto exit;
}
V_3 = F_39 ( V_38 ) ;
if ( ! V_3 ) {
V_19 = - V_54 ;
goto exit;
}
F_48 ( & V_3 -> V_8 ) ;
F_41 ( & V_3 -> V_48 ) ;
V_72 -> V_74 = V_3 ;
F_42 ( & V_3 -> V_48 ) ;
exit:
return V_19 ;
}
static int F_49 ( struct V_75 * V_75 , struct V_72 * V_72 )
{
struct V_2 * V_3 ;
V_3 = (struct V_2 * ) V_72 -> V_74 ;
if ( V_3 == NULL )
return - V_54 ;
F_43 ( - 1 , V_72 , 0 ) ;
F_37 ( & V_3 -> V_8 , F_4 ) ;
return 0 ;
}
static T_1 F_50 ( struct V_72 * V_72 , char * V_78 , T_2 V_79 , T_3 * V_80 )
{
struct V_2 * V_3 ;
int V_19 = 0 ;
int V_81 = 0 ;
char V_82 [ 20 ] ;
unsigned long V_18 ;
V_3 = (struct V_2 * ) V_72 -> V_74 ;
F_41 ( & V_3 -> V_48 ) ;
if ( ! V_3 -> V_38 ) {
V_19 = - V_54 ;
goto exit;
}
F_13 ( & V_3 -> V_30 , V_18 ) ;
V_81 = snprintf ( V_82 , 20 , L_21 , V_3 -> V_31 ) ;
F_14 ( & V_3 -> V_30 , V_18 ) ;
if ( * V_80 < V_81 ) {
if ( F_51 ( V_78 , V_82 + * V_80 , V_81 - * V_80 ) )
V_19 = - V_83 ;
else {
V_19 = V_81 - * V_80 ;
* V_80 += V_81 ;
}
}
exit:
F_42 ( & V_3 -> V_48 ) ;
return V_19 ;
}
static T_1 F_52 ( struct V_72 * V_72 , const char * V_84 , T_2 V_79 , T_3 * V_80 )
{
struct V_2 * V_3 ;
int V_20 , V_85 = 0 , V_19 = 0 ;
char V_78 [ 16 ] ;
char * V_86 = V_78 ;
unsigned long long V_87 , V_88 = 0 ;
signed long V_89 = 0 ;
F_18 ( V_46 ) ;
V_79 = F_53 ( sizeof( V_78 ) , V_79 ) ;
V_3 = (struct V_2 * ) V_72 -> V_74 ;
if ( V_79 == 0 )
goto error;
F_41 ( & V_3 -> V_48 ) ;
if ( ! V_3 -> V_38 ) {
F_42 ( & V_3 -> V_48 ) ;
V_19 = - V_54 ;
goto error;
}
if ( F_54 ( V_78 , V_84 , V_79 ) ) {
F_42 ( & V_3 -> V_48 ) ;
V_19 = - V_83 ;
goto error;
}
memset ( V_3 -> V_14 , V_90 , V_12 ) ;
switch ( V_78 [ 0 ] ) {
case V_91 :
case V_92 :
V_3 -> V_14 [ 0 ] = V_78 [ 0 ] ;
V_3 -> V_14 [ 1 ] = V_78 [ 1 ] ;
V_3 -> V_14 [ 2 ] = V_29 ;
break;
case V_28 :
case V_93 :
V_3 -> V_14 [ 0 ] = V_78 [ 0 ] ;
V_3 -> V_14 [ 1 ] = 0x00 ;
V_3 -> V_14 [ 2 ] = V_29 ;
break;
case V_94 :
V_86 ++ ;
case '0' ... '9' :
V_85 = 1 ;
V_87 = V_88 = F_55 ( V_86 , NULL , 0 ) ;
V_3 -> V_14 [ 0 ] = V_94 ;
for ( V_20 = 1 ; V_20 < 6 ; V_20 ++ ) {
V_3 -> V_14 [ V_20 ] = ( V_87 >> 32 ) & 0xff ;
V_87 <<= 8 ;
}
V_78 [ 6 ] = V_29 ;
break;
default:
F_42 ( & V_3 -> V_48 ) ;
return - V_95 ;
}
F_56 ( & V_3 -> V_7 , & V_46 , V_96 ) ;
F_6 ( L_22 , V_6 , V_3 -> V_14 [ 0 ] ) ;
V_19 = F_16 ( V_3 -> V_10 , V_47 ) ;
if ( V_19 >= 0 )
V_89 = F_57 ( V_97 ) ;
F_58 ( & V_3 -> V_7 , & V_46 ) ;
F_42 ( & V_3 -> V_48 ) ;
if ( V_19 < 0 ) {
F_2 ( L_23 , V_6 , V_19 ) ;
goto error;
}
if ( V_85 && V_89 )
V_3 -> V_31 = V_88 ;
return V_89 ? V_79 : - V_68 ;
error:
return V_19 ;
}
static int T_4 F_59 ( void )
{
int V_98 ;
V_98 = F_60 ( & V_77 ) ;
if ( V_98 )
F_2 ( L_24 , V_98 ) ;
return V_98 ;
}
static void T_5 F_61 ( void )
{
F_62 ( & V_77 ) ;
}
