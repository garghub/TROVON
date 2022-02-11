static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , V_6 ,
F_4 ( V_4 -> V_7 ) , F_4 ( V_4 -> V_7 ) ) ;
return 0 ;
}
static void F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
F_3 ( V_4 -> V_5 , V_6 ,
F_4 ( V_4 -> V_7 ) , 0 ) ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
T_1 V_8 ;
F_7 ( V_4 -> V_5 , V_6 , & V_8 ) ;
return V_8 & F_4 ( V_4 -> V_7 ) ;
}
static struct V_1 * F_8 ( const char * V_9 ,
const char * V_10 ,
struct V_5 * V_5 , T_2 V_7 )
{
struct V_3 * V_4 ;
struct V_1 * V_2 ;
struct V_11 V_12 ;
int V_13 ;
V_4 = F_9 ( sizeof( * V_4 ) , V_14 ) ;
if ( ! V_4 )
return F_10 ( - V_15 ) ;
memset ( & V_12 , 0 , sizeof( V_12 ) ) ;
V_12 . V_9 = V_9 ;
V_12 . V_16 = & V_17 ;
V_12 . V_18 = & V_10 ;
V_12 . V_19 = 1 ;
V_4 -> V_5 = V_5 ;
V_4 -> V_7 = V_7 ;
V_4 -> V_2 . V_12 = & V_12 ;
V_2 = & V_4 -> V_2 ;
V_13 = F_11 ( NULL , V_2 ) ;
if ( V_13 ) {
F_12 ( V_4 ) ;
V_2 = F_10 ( V_13 ) ;
}
return V_2 ;
}
static void F_13 ( struct V_1 * V_2 )
{
F_14 ( V_2 ) ;
F_12 ( F_2 ( V_2 ) ) ;
}
static struct V_1 * F_15 ( struct V_20 * V_21 ,
void * V_22 )
{
struct V_23 * V_24 = V_22 ;
unsigned int type = V_21 -> args [ 0 ] ;
unsigned int V_25 = V_21 -> args [ 1 ] ;
if ( type == V_26 ) {
if ( V_25 > V_27 )
return F_10 ( - V_28 ) ;
return V_24 -> V_29 [ V_25 ] ;
} else if ( type == V_30 ) {
if ( V_25 > V_31 )
return F_10 ( - V_28 ) ;
return V_24 -> V_29 [ V_27 + V_25 ] ;
}
return F_10 ( - V_28 ) ;
}
static char * F_16 ( struct V_32 * V_33 , struct V_34 * V_35 ,
const char * V_9 )
{
const T_3 * V_36 ;
T_4 V_37 ;
if ( ! V_9 )
return NULL ;
V_36 = F_17 ( V_35 , L_1 , NULL ) ;
V_37 = F_18 ( V_35 , V_36 ) ;
return F_19 ( V_33 , V_14 , L_2 ,
( unsigned long long ) V_37 , V_9 ) ;
}
static int F_20 ( struct V_38 * V_39 ,
struct V_34 * V_40 )
{
struct V_5 * V_5 ;
struct V_32 * V_33 = & V_39 -> V_33 ;
struct V_34 * V_35 = V_33 -> V_41 ;
const char * V_42 , * V_43 , * V_44 , * V_45 , * V_46 ,
* V_47 ;
struct V_23 * V_48 ;
struct V_1 * V_2 , * * V_49 ;
T_1 V_50 ;
int V_51 , V_13 ;
char * V_52 [ F_21 ( V_53 ) ] ;
V_5 = F_22 ( V_40 ) ;
if ( F_23 ( V_5 ) )
return F_24 ( V_5 ) ;
V_13 = F_7 ( V_5 , V_54 ,
& V_50 ) ;
if ( V_13 )
return V_13 ;
V_48 = F_25 ( V_33 , sizeof( * V_48 ) +
sizeof( struct V_1 * ) * V_55 ,
V_14 ) ;
if ( ! V_48 )
return - V_15 ;
V_49 = V_48 -> V_29 ;
V_48 -> V_56 = V_55 ;
V_43 = F_16 ( V_33 , V_40 , L_3 ) ;
V_2 = F_26 ( NULL , V_43 , NULL , 0 ,
1000 * 1000 * 1000 ) ;
if ( F_23 ( V_2 ) ) {
V_13 = F_24 ( V_2 ) ;
goto V_57;
}
V_49 [ V_58 ] = V_2 ;
V_42 = F_16 ( V_33 , V_40 , L_4 ) ;
V_2 = F_27 ( NULL , V_42 , V_43 , 0 , 1 , 3 ) ;
if ( F_23 ( V_2 ) ) {
V_13 = F_24 ( V_2 ) ;
goto V_59;
}
V_49 [ V_60 ] = V_2 ;
V_45 = F_16 ( V_33 , V_40 , L_5 ) ;
V_2 = F_27 ( NULL , V_45 , V_43 , 0 , 1 , 2 ) ;
if ( F_23 ( V_2 ) ) {
V_13 = F_24 ( V_2 ) ;
goto V_61;
}
V_49 [ V_62 ] = V_2 ;
V_44 = F_16 ( V_33 , V_40 , L_6 ) ;
V_2 = F_27 ( NULL , V_44 , V_45 , 0 , 1 , 2 ) ;
if ( F_23 ( V_2 ) ) {
V_13 = F_24 ( V_2 ) ;
goto V_63;
}
V_49 [ V_64 ] = V_2 ;
V_46 = F_16 ( V_33 , V_40 , L_7 ) ;
if ( V_50 & V_65 )
V_2 = F_27 ( NULL , V_46 ,
V_43 , 0 , 2 , 5 ) ;
else
V_2 = F_27 ( NULL , V_46 ,
V_44 , 0 , 1 , 1 ) ;
if ( F_23 ( V_2 ) ) {
V_13 = F_24 ( V_2 ) ;
goto V_66;
}
V_49 [ V_67 ] = V_2 ;
V_47 = F_16 ( V_33 , V_40 , L_8 ) ;
V_2 = F_27 ( NULL , V_47 ,
V_43 , 0 , 2 , 5 ) ;
if ( F_23 ( V_2 ) ) {
V_13 = F_24 ( V_2 ) ;
goto V_68;
}
V_49 [ V_69 ] = V_2 ;
for ( V_51 = 0 ; V_51 < F_21 ( V_53 ) ; V_51 ++ )
V_52 [ V_51 ] = F_16 ( V_33 , V_40 ,
V_53 [ V_51 ] ) ;
for ( V_51 = 0 ; V_51 < F_21 ( V_53 ) ; V_51 ++ ) {
const char * V_70 ;
if ( V_52 [ V_51 ] == NULL )
continue;
switch ( V_51 ) {
case V_71 :
case V_72 :
case V_73 :
case V_74 :
case V_75 :
V_70 = V_52 [ V_76 ] ;
break;
case V_77 :
V_70 = V_52 [ V_78 ] ;
break;
case V_79 :
V_70 = V_46 ;
break;
case V_80 :
V_70 = V_42 ;
break;
case V_81 :
V_70 = V_47 ;
break;
case V_82 :
V_70 = V_52 [ V_83 ] ;
break;
case V_84 :
case V_85 :
case V_86 :
case V_87 :
case V_88 :
V_70 = V_52 [ V_89 ] ;
break;
case V_90 :
case V_91 :
case V_92 :
case V_93 :
V_70 = V_52 [ V_94 ] ;
break;
default:
V_70 = V_44 ;
break;
}
V_2 = F_8 ( V_52 [ V_51 ] , V_70 , V_5 , V_51 ) ;
if ( F_23 ( V_2 ) ) {
V_13 = F_24 ( V_2 ) ;
goto V_95;
}
V_49 [ V_27 + V_51 ] = V_2 ;
}
V_13 = F_28 ( V_35 , F_15 , V_48 ) ;
if ( V_13 )
goto V_96;
F_29 ( V_39 , V_49 ) ;
return 0 ;
V_96:
V_95:
for ( V_51 = 0 ; V_51 < V_31 ; V_51 ++ ) {
V_2 = V_49 [ V_27 + V_51 ] ;
if ( V_2 )
F_13 ( V_2 ) ;
}
F_30 ( V_49 [ V_69 ] ) ;
V_68:
F_30 ( V_49 [ V_67 ] ) ;
V_66:
F_30 ( V_49 [ V_64 ] ) ;
V_63:
F_30 ( V_49 [ V_62 ] ) ;
V_61:
F_30 ( V_49 [ V_60 ] ) ;
V_59:
F_31 ( V_49 [ V_58 ] ) ;
V_57:
return V_13 ;
}
static int F_32 ( struct V_38 * V_39 )
{
F_33 ( & V_39 -> V_33 , V_97 L_9 ) ;
F_33 ( & V_39 -> V_33 , V_97 L_10 ) ;
F_33 ( & V_39 -> V_33 , V_97
L_11 ) ;
return F_20 ( V_39 , V_39 -> V_33 . V_41 ) ;
}
static int F_34 ( struct V_38 * V_39 )
{
return F_20 ( V_39 , V_39 -> V_33 . V_41 -> V_70 ) ;
}
