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
F_9 ( V_3 -> V_11 ) ;
if ( V_3 -> V_12 )
F_10 ( V_3 -> V_9 , V_13 ,
V_3 -> V_12 , V_3 -> V_10 -> V_14 ) ;
F_11 ( V_3 -> V_10 ) ;
}
if ( V_3 -> V_1 ) {
F_8 ( V_3 -> V_1 ) ;
if ( V_3 -> V_15 )
F_10 ( V_3 -> V_9 , V_13 ,
V_3 -> V_15 , V_3 -> V_1 -> V_14 ) ;
F_11 ( V_3 -> V_1 ) ;
}
F_9 ( V_3 ) ;
}
static void F_12 ( struct V_1 * V_1 )
{
struct V_2 * V_3 = V_1 -> V_4 ;
unsigned char * V_16 = V_3 -> V_15 ;
int V_5 = V_1 -> V_5 ;
unsigned long V_17 ;
int V_18 , V_19 ;
switch ( V_5 ) {
case 0 :
break;
case - V_20 :
F_2 ( L_3 ,
V_6 , V_13 , V_3 -> V_1 -> V_21 ) ;
case - V_22 :
case - V_23 :
case - V_24 :
case - V_25 :
return;
default:
F_2 ( L_4 , V_6 , V_5 ) ;
goto exit;
}
switch ( V_16 [ 0 ] ) {
case V_26 :
case V_27 :
if ( V_16 [ 6 ] == V_28 ) {
F_13 ( & V_3 -> V_29 , V_17 ) ;
V_3 -> V_30 = 0 ;
for ( V_19 = 1 ; V_19 < 6 ; V_19 ++ ) {
V_3 -> V_30 += V_16 [ V_19 ] ;
if ( V_19 != 5 )
V_3 -> V_30 <<= 8 ;
}
F_6 ( L_5 , V_6 , V_3 -> V_30 ) ;
F_14 ( & V_3 -> V_29 , V_17 ) ;
F_15 ( & V_3 -> V_31 , V_32 , V_33 ) ;
}
else
F_6 ( L_6 ) ;
break;
case V_34 :
F_6 ( L_7 , V_6 , V_16 [ 1 ] ) ;
F_3 ( & V_3 -> V_7 ) ;
break;
}
exit:
V_18 = F_16 ( V_3 -> V_1 , V_35 ) ;
if ( V_18 ) {
F_2 ( L_8 ,
V_6 , V_18 ) ;
}
}
static int F_17 ( struct V_36 * V_37 , const struct V_38 * V_39 )
{
struct V_2 * V_3 ;
struct V_40 * V_41 ;
struct V_42 * V_43 ;
int V_18 = - V_44 ;
int V_19 ;
F_18 ( V_45 ) ;
V_3 = F_19 ( sizeof( * V_3 ) , V_46 ) ;
if ( ! V_3 ) {
F_2 ( L_9 ) ;
goto error;
}
F_20 ( & V_3 -> V_8 ) ;
F_21 ( & V_3 -> V_47 ) ;
F_22 ( & V_3 -> V_29 ) ;
F_23 ( & V_3 -> V_7 ) ;
V_3 -> V_9 = F_24 ( F_25 ( V_37 ) ) ;
V_3 -> V_37 = V_37 ;
V_41 = V_37 -> V_48 ;
for ( V_19 = 0 ; V_19 < V_41 -> V_49 . V_50 ; V_19 ++ ) {
V_43 = & V_41 -> V_43 [ V_19 ] . V_49 ;
if ( F_26 ( V_43 ) ) {
V_3 -> V_51 = V_43 -> V_52 ;
break;
}
}
if ( ! V_3 -> V_51 ) {
V_18 = - V_53 ;
F_2 ( L_10 ) ;
goto error;
}
V_3 -> V_10 = F_27 ( 0 , V_46 ) ;
if ( ! V_3 -> V_10 ) {
F_2 ( L_11 ) ;
goto error;
}
V_3 -> V_11 = F_28 ( V_13 , V_46 ) ;
if ( ! V_3 -> V_11 ) {
F_2 ( L_12 ) ;
goto error;
}
V_3 -> V_12 = F_29 ( V_3 -> V_9 , V_13 ,
V_46 ,
& V_3 -> V_10 -> V_14 ) ;
if ( ! V_3 -> V_12 ) {
F_2 ( L_13 ) ;
goto error;
}
V_3 -> V_11 -> V_54 = V_55 | V_56 |
V_57 ;
V_3 -> V_11 -> V_58 = V_59 ;
V_3 -> V_11 -> V_60 = F_30 ( ( V_61 + 1 ) << 8 ) ;
V_3 -> V_11 -> V_62 = F_30 ( V_41 -> V_49 . V_63 ) ;
V_3 -> V_11 -> V_64 = F_30 ( V_13 ) ;
F_31 ( V_3 -> V_10 , V_3 -> V_9 ,
F_32 ( V_3 -> V_9 , 0 ) ,
( void * ) V_3 -> V_11 , V_3 -> V_12 ,
V_13 , F_1 , V_3 ) ;
V_3 -> V_10 -> V_65 |= V_66 ;
V_3 -> V_1 = F_27 ( 0 , V_46 ) ;
if ( ! V_3 -> V_1 ) {
F_2 ( L_14 ) ;
goto error;
}
V_3 -> V_15 = F_29 ( V_3 -> V_9 , V_13 ,
V_46 , & V_3 -> V_1 -> V_14 ) ;
if ( ! V_3 -> V_15 ) {
F_2 ( L_15 ) ;
goto error;
}
F_33 ( V_3 -> V_1 , V_3 -> V_9 ,
F_34 ( V_3 -> V_9 , V_3 -> V_51 ) ,
V_3 -> V_15 , V_13 , F_12 ,
V_3 , 1 ) ;
V_3 -> V_1 -> V_65 |= V_66 ;
if ( F_16 ( V_3 -> V_1 , V_46 ) ) {
V_18 = - V_67 ;
F_2 ( L_16 ) ;
goto error;
}
F_35 ( V_37 , V_3 ) ;
V_18 = F_36 ( V_37 , & V_68 ) ;
if ( V_18 ) {
F_2 ( L_17 ) ;
F_35 ( V_37 , NULL ) ;
goto error;
}
V_3 -> V_30 = - 1 ;
F_37 ( & V_37 -> V_3 ,
L_18 ,
V_37 -> V_69 ) ;
return 0 ;
error:
if ( V_3 )
F_38 ( & V_3 -> V_8 , F_4 ) ;
return V_18 ;
}
static void F_39 ( struct V_36 * V_37 )
{
struct V_2 * V_3 ;
int V_69 = V_37 -> V_69 ;
V_3 = F_40 ( V_37 ) ;
F_35 ( V_37 , NULL ) ;
F_41 ( V_37 , & V_68 ) ;
F_42 ( & V_3 -> V_47 ) ;
V_3 -> V_37 = NULL ;
F_43 ( & V_3 -> V_47 ) ;
F_15 ( & V_3 -> V_31 , V_32 , V_33 ) ;
F_3 ( & V_3 -> V_7 ) ;
F_38 ( & V_3 -> V_8 , F_4 ) ;
F_37 ( & V_37 -> V_3 , L_19 , V_69 ) ;
}
static int F_44 ( int V_70 , struct V_71 * V_71 , int V_72 )
{
struct V_2 * V_3 ;
V_3 = (struct V_2 * ) V_71 -> V_73 ;
return F_45 ( V_70 , V_71 , V_72 , & V_3 -> V_31 ) ;
}
static int F_46 ( struct V_74 * V_74 , struct V_71 * V_71 )
{
struct V_2 * V_3 ;
struct V_36 * V_37 ;
int V_75 ;
int V_18 = 0 ;
V_75 = F_47 ( V_74 ) ;
V_37 = F_48 ( & V_76 , V_75 ) ;
if ( ! V_37 ) {
F_2 ( L_20 ,
V_6 , V_75 ) ;
V_18 = - V_53 ;
goto exit;
}
V_3 = F_40 ( V_37 ) ;
if ( ! V_3 ) {
V_18 = - V_53 ;
goto exit;
}
F_49 ( & V_3 -> V_8 ) ;
F_42 ( & V_3 -> V_47 ) ;
V_71 -> V_73 = V_3 ;
F_43 ( & V_3 -> V_47 ) ;
exit:
return V_18 ;
}
static int F_50 ( struct V_74 * V_74 , struct V_71 * V_71 )
{
struct V_2 * V_3 ;
V_3 = (struct V_2 * ) V_71 -> V_73 ;
if ( V_3 == NULL )
return - V_53 ;
F_44 ( - 1 , V_71 , 0 ) ;
F_38 ( & V_3 -> V_8 , F_4 ) ;
return 0 ;
}
static T_1 F_51 ( struct V_71 * V_71 , char * V_77 , T_2 V_78 , T_3 * V_79 )
{
struct V_2 * V_3 ;
int V_18 = 0 ;
int V_80 = 0 ;
char V_81 [ 20 ] ;
unsigned long V_17 ;
V_3 = (struct V_2 * ) V_71 -> V_73 ;
F_42 ( & V_3 -> V_47 ) ;
if ( ! V_3 -> V_37 ) {
V_18 = - V_53 ;
goto exit;
}
F_13 ( & V_3 -> V_29 , V_17 ) ;
V_80 = snprintf ( V_81 , 20 , L_21 , V_3 -> V_30 ) ;
F_14 ( & V_3 -> V_29 , V_17 ) ;
if ( * V_79 < V_80 ) {
if ( F_52 ( V_77 , V_81 + * V_79 , V_80 - * V_79 ) )
V_18 = - V_82 ;
else {
V_18 = V_80 - * V_79 ;
* V_79 += V_80 ;
}
}
exit:
F_43 ( & V_3 -> V_47 ) ;
return V_18 ;
}
static T_1 F_53 ( struct V_71 * V_71 , const char * V_83 , T_2 V_78 , T_3 * V_79 )
{
struct V_2 * V_3 ;
int V_19 , V_84 = 0 , V_18 = 0 ;
char V_77 [ 16 ] ;
char * V_85 = V_77 ;
unsigned long long V_86 , V_87 = 0 ;
signed long V_88 = 0 ;
F_18 ( V_45 ) ;
V_78 = F_54 ( sizeof( V_77 ) , V_78 ) ;
V_3 = (struct V_2 * ) V_71 -> V_73 ;
if ( V_78 == 0 )
goto error;
F_42 ( & V_3 -> V_47 ) ;
if ( ! V_3 -> V_37 ) {
F_43 ( & V_3 -> V_47 ) ;
V_18 = - V_53 ;
goto error;
}
if ( F_55 ( V_77 , V_83 , V_78 ) ) {
F_43 ( & V_3 -> V_47 ) ;
V_18 = - V_82 ;
goto error;
}
memset ( V_3 -> V_12 , V_89 , V_13 ) ;
switch ( V_77 [ 0 ] ) {
case V_90 :
case V_91 :
V_3 -> V_12 [ 0 ] = V_77 [ 0 ] ;
V_3 -> V_12 [ 1 ] = V_77 [ 1 ] ;
V_3 -> V_12 [ 2 ] = V_28 ;
break;
case V_27 :
case V_92 :
V_3 -> V_12 [ 0 ] = V_77 [ 0 ] ;
V_3 -> V_12 [ 1 ] = 0x00 ;
V_3 -> V_12 [ 2 ] = V_28 ;
break;
case V_93 :
V_85 ++ ;
case '0' ... '9' :
V_84 = 1 ;
V_86 = V_87 = F_56 ( V_85 , NULL , 0 ) ;
V_3 -> V_12 [ 0 ] = V_93 ;
for ( V_19 = 1 ; V_19 < 6 ; V_19 ++ ) {
V_3 -> V_12 [ V_19 ] = ( V_86 >> 32 ) & 0xff ;
V_86 <<= 8 ;
}
V_77 [ 6 ] = V_28 ;
break;
default:
F_43 ( & V_3 -> V_47 ) ;
return - V_94 ;
}
F_57 ( & V_3 -> V_7 , & V_45 , V_95 ) ;
F_6 ( L_22 , V_6 , V_3 -> V_12 [ 0 ] ) ;
V_18 = F_16 ( V_3 -> V_10 , V_46 ) ;
if ( V_18 >= 0 )
V_88 = F_58 ( V_96 ) ;
F_59 ( & V_3 -> V_7 , & V_45 ) ;
F_43 ( & V_3 -> V_47 ) ;
if ( V_18 < 0 ) {
F_2 ( L_23 , V_6 , V_18 ) ;
goto error;
}
if ( V_84 && V_88 )
V_3 -> V_30 = V_87 ;
return V_88 ? V_78 : - V_67 ;
error:
return V_18 ;
}
