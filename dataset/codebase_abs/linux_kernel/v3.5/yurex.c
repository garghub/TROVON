static void F_1 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
int V_5 = V_1 -> V_5 ;
if ( V_5 ) {
F_2 ( & V_1 -> V_3 -> V_3 , L_1 ,
V_6 , V_5 ) ;
F_3 ( & V_3 -> V_7 ) ;
return;
}
}
static void F_4 ( struct V_8 * V_8 )
{
struct V_2 * V_3 = F_5 ( V_8 ) ;
F_6 ( & V_3 -> V_9 -> V_3 , L_2 , V_6 ) ;
F_7 ( V_3 -> V_10 ) ;
if ( V_3 -> V_11 ) {
F_8 ( V_3 -> V_11 ) ;
F_9 ( V_3 -> V_12 ) ;
if ( V_3 -> V_13 )
F_10 ( V_3 -> V_10 , V_14 ,
V_3 -> V_13 , V_3 -> V_11 -> V_15 ) ;
F_11 ( V_3 -> V_11 ) ;
}
if ( V_3 -> V_1 ) {
F_8 ( V_3 -> V_1 ) ;
if ( V_3 -> V_16 )
F_10 ( V_3 -> V_10 , V_14 ,
V_3 -> V_16 , V_3 -> V_1 -> V_15 ) ;
F_11 ( V_3 -> V_1 ) ;
}
F_9 ( V_3 ) ;
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
F_2 ( & V_3 -> V_9 -> V_3 ,
L_3 ,
V_6 , V_14 , V_3 -> V_1 -> V_22 ) ;
case - V_23 :
case - V_24 :
case - V_25 :
case - V_26 :
return;
default:
F_2 ( & V_3 -> V_9 -> V_3 ,
L_4 , V_6 , V_5 ) ;
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
F_6 ( & V_3 -> V_9 -> V_3 , L_5 ,
V_6 , V_3 -> V_31 ) ;
F_14 ( & V_3 -> V_30 , V_18 ) ;
F_15 ( & V_3 -> V_32 , V_33 , V_34 ) ;
}
else
F_6 ( & V_3 -> V_9 -> V_3 ,
L_6 ) ;
break;
case V_35 :
F_6 ( & V_3 -> V_9 -> V_3 , L_7 ,
V_6 , V_17 [ 1 ] ) ;
F_3 ( & V_3 -> V_7 ) ;
break;
}
exit:
V_19 = F_16 ( V_3 -> V_1 , V_36 ) ;
if ( V_19 ) {
F_2 ( & V_3 -> V_9 -> V_3 , L_8 ,
V_6 , V_19 ) ;
}
}
static int F_17 ( struct V_37 * V_9 , const struct V_38 * V_39 )
{
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
int V_19 = - V_44 ;
int V_20 ;
F_18 ( V_45 ) ;
V_3 = F_19 ( sizeof( * V_3 ) , V_46 ) ;
if ( ! V_3 ) {
F_2 ( & V_9 -> V_3 , L_9 ) ;
goto error;
}
F_20 ( & V_3 -> V_8 ) ;
F_21 ( & V_3 -> V_47 ) ;
F_22 ( & V_3 -> V_30 ) ;
F_23 ( & V_3 -> V_7 ) ;
V_3 -> V_10 = F_24 ( F_25 ( V_9 ) ) ;
V_3 -> V_9 = V_9 ;
V_41 = V_9 -> V_48 ;
for ( V_20 = 0 ; V_20 < V_41 -> V_49 . V_50 ; V_20 ++ ) {
V_43 = & V_41 -> V_43 [ V_20 ] . V_49 ;
if ( F_26 ( V_43 ) ) {
V_3 -> V_51 = V_43 -> V_52 ;
break;
}
}
if ( ! V_3 -> V_51 ) {
V_19 = - V_53 ;
F_2 ( & V_9 -> V_3 , L_10 ) ;
goto error;
}
V_3 -> V_11 = F_27 ( 0 , V_46 ) ;
if ( ! V_3 -> V_11 ) {
F_2 ( & V_9 -> V_3 , L_11 ) ;
goto error;
}
V_3 -> V_12 = F_28 ( V_14 , V_46 ) ;
if ( ! V_3 -> V_12 ) {
F_2 ( & V_9 -> V_3 , L_12 ) ;
goto error;
}
V_3 -> V_13 = F_29 ( V_3 -> V_10 , V_14 ,
V_46 ,
& V_3 -> V_11 -> V_15 ) ;
if ( ! V_3 -> V_13 ) {
F_2 ( & V_9 -> V_3 , L_13 ) ;
goto error;
}
V_3 -> V_12 -> V_54 = V_55 | V_56 |
V_57 ;
V_3 -> V_12 -> V_58 = V_59 ;
V_3 -> V_12 -> V_60 = F_30 ( ( V_61 + 1 ) << 8 ) ;
V_3 -> V_12 -> V_62 = F_30 ( V_41 -> V_49 . V_63 ) ;
V_3 -> V_12 -> V_64 = F_30 ( V_14 ) ;
F_31 ( V_3 -> V_11 , V_3 -> V_10 ,
F_32 ( V_3 -> V_10 , 0 ) ,
( void * ) V_3 -> V_12 , V_3 -> V_13 ,
V_14 , F_1 , V_3 ) ;
V_3 -> V_11 -> V_65 |= V_66 ;
V_3 -> V_1 = F_27 ( 0 , V_46 ) ;
if ( ! V_3 -> V_1 ) {
F_2 ( & V_9 -> V_3 , L_14 ) ;
goto error;
}
V_3 -> V_16 = F_29 ( V_3 -> V_10 , V_14 ,
V_46 , & V_3 -> V_1 -> V_15 ) ;
if ( ! V_3 -> V_16 ) {
F_2 ( & V_9 -> V_3 , L_15 ) ;
goto error;
}
F_33 ( V_3 -> V_1 , V_3 -> V_10 ,
F_34 ( V_3 -> V_10 , V_3 -> V_51 ) ,
V_3 -> V_16 , V_14 , F_12 ,
V_3 , 1 ) ;
V_3 -> V_1 -> V_65 |= V_66 ;
if ( F_16 ( V_3 -> V_1 , V_46 ) ) {
V_19 = - V_67 ;
F_2 ( & V_9 -> V_3 , L_16 ) ;
goto error;
}
F_35 ( V_9 , V_3 ) ;
V_19 = F_36 ( V_9 , & V_68 ) ;
if ( V_19 ) {
F_2 ( & V_9 -> V_3 ,
L_17 ) ;
F_35 ( V_9 , NULL ) ;
goto error;
}
V_3 -> V_31 = - 1 ;
F_37 ( & V_9 -> V_3 ,
L_18 ,
V_9 -> V_69 ) ;
return 0 ;
error:
if ( V_3 )
F_38 ( & V_3 -> V_8 , F_4 ) ;
return V_19 ;
}
static void F_39 ( struct V_37 * V_9 )
{
struct V_2 * V_3 ;
int V_69 = V_9 -> V_69 ;
V_3 = F_40 ( V_9 ) ;
F_35 ( V_9 , NULL ) ;
F_41 ( V_9 , & V_68 ) ;
F_42 ( & V_3 -> V_47 ) ;
V_3 -> V_9 = NULL ;
F_43 ( & V_3 -> V_47 ) ;
F_15 ( & V_3 -> V_32 , V_33 , V_34 ) ;
F_3 ( & V_3 -> V_7 ) ;
F_38 ( & V_3 -> V_8 , F_4 ) ;
F_37 ( & V_9 -> V_3 , L_19 , V_69 ) ;
}
static int F_44 ( int V_70 , struct V_71 * V_71 , int V_72 )
{
struct V_2 * V_3 ;
V_3 = (struct V_2 * ) V_71 -> V_73 ;
return F_45 ( V_70 , V_71 , V_72 , & V_3 -> V_32 ) ;
}
static int F_46 ( struct V_74 * V_74 , struct V_71 * V_71 )
{
struct V_2 * V_3 ;
struct V_37 * V_9 ;
int V_75 ;
int V_19 = 0 ;
V_75 = F_47 ( V_74 ) ;
V_9 = F_48 ( & V_76 , V_75 ) ;
if ( ! V_9 ) {
F_49 ( V_77 L_20 ,
V_6 , V_75 ) ;
V_19 = - V_53 ;
goto exit;
}
V_3 = F_40 ( V_9 ) ;
if ( ! V_3 ) {
V_19 = - V_53 ;
goto exit;
}
F_50 ( & V_3 -> V_8 ) ;
F_42 ( & V_3 -> V_47 ) ;
V_71 -> V_73 = V_3 ;
F_43 ( & V_3 -> V_47 ) ;
exit:
return V_19 ;
}
static int F_51 ( struct V_74 * V_74 , struct V_71 * V_71 )
{
struct V_2 * V_3 ;
V_3 = (struct V_2 * ) V_71 -> V_73 ;
if ( V_3 == NULL )
return - V_53 ;
F_44 ( - 1 , V_71 , 0 ) ;
F_38 ( & V_3 -> V_8 , F_4 ) ;
return 0 ;
}
static T_1 F_52 ( struct V_71 * V_71 , char * V_78 , T_2 V_79 , T_3 * V_80 )
{
struct V_2 * V_3 ;
int V_19 = 0 ;
int V_81 = 0 ;
char V_82 [ 20 ] ;
unsigned long V_18 ;
V_3 = (struct V_2 * ) V_71 -> V_73 ;
F_42 ( & V_3 -> V_47 ) ;
if ( ! V_3 -> V_9 ) {
V_19 = - V_53 ;
goto exit;
}
F_13 ( & V_3 -> V_30 , V_18 ) ;
V_81 = snprintf ( V_82 , 20 , L_21 , V_3 -> V_31 ) ;
F_14 ( & V_3 -> V_30 , V_18 ) ;
if ( * V_80 < V_81 ) {
if ( F_53 ( V_78 , V_82 + * V_80 , V_81 - * V_80 ) )
V_19 = - V_83 ;
else {
V_19 = V_81 - * V_80 ;
* V_80 += V_81 ;
}
}
exit:
F_43 ( & V_3 -> V_47 ) ;
return V_19 ;
}
static T_1 F_54 ( struct V_71 * V_71 , const char * V_84 , T_2 V_79 , T_3 * V_80 )
{
struct V_2 * V_3 ;
int V_20 , V_85 = 0 , V_19 = 0 ;
char V_78 [ 16 ] ;
char * V_86 = V_78 ;
unsigned long long V_87 , V_88 = 0 ;
signed long V_89 = 0 ;
F_18 ( V_45 ) ;
V_79 = F_55 ( sizeof( V_78 ) , V_79 ) ;
V_3 = (struct V_2 * ) V_71 -> V_73 ;
if ( V_79 == 0 )
goto error;
F_42 ( & V_3 -> V_47 ) ;
if ( ! V_3 -> V_9 ) {
F_43 ( & V_3 -> V_47 ) ;
V_19 = - V_53 ;
goto error;
}
if ( F_56 ( V_78 , V_84 , V_79 ) ) {
F_43 ( & V_3 -> V_47 ) ;
V_19 = - V_83 ;
goto error;
}
memset ( V_3 -> V_13 , V_90 , V_14 ) ;
switch ( V_78 [ 0 ] ) {
case V_91 :
case V_92 :
V_3 -> V_13 [ 0 ] = V_78 [ 0 ] ;
V_3 -> V_13 [ 1 ] = V_78 [ 1 ] ;
V_3 -> V_13 [ 2 ] = V_29 ;
break;
case V_28 :
case V_93 :
V_3 -> V_13 [ 0 ] = V_78 [ 0 ] ;
V_3 -> V_13 [ 1 ] = 0x00 ;
V_3 -> V_13 [ 2 ] = V_29 ;
break;
case V_94 :
V_86 ++ ;
case '0' ... '9' :
V_85 = 1 ;
V_87 = V_88 = F_57 ( V_86 , NULL , 0 ) ;
V_3 -> V_13 [ 0 ] = V_94 ;
for ( V_20 = 1 ; V_20 < 6 ; V_20 ++ ) {
V_3 -> V_13 [ V_20 ] = ( V_87 >> 32 ) & 0xff ;
V_87 <<= 8 ;
}
V_78 [ 6 ] = V_29 ;
break;
default:
F_43 ( & V_3 -> V_47 ) ;
return - V_95 ;
}
F_58 ( & V_3 -> V_7 , & V_45 , V_96 ) ;
F_6 ( & V_3 -> V_9 -> V_3 , L_22 , V_6 ,
V_3 -> V_13 [ 0 ] ) ;
V_19 = F_16 ( V_3 -> V_11 , V_46 ) ;
if ( V_19 >= 0 )
V_89 = F_59 ( V_97 ) ;
F_60 ( & V_3 -> V_7 , & V_45 ) ;
F_43 ( & V_3 -> V_47 ) ;
if ( V_19 < 0 ) {
F_2 ( & V_3 -> V_9 -> V_3 ,
L_23 ,
V_6 , V_19 ) ;
goto error;
}
if ( V_85 && V_89 )
V_3 -> V_31 = V_88 ;
return V_89 ? V_79 : - V_67 ;
error:
return V_19 ;
}
