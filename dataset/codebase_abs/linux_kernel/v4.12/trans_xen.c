static int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 )
{
return 1 ;
}
static int F_2 ( struct V_1 * V_2 , const char * V_5 , char * args )
{
struct V_6 * V_7 ;
F_3 ( & V_8 ) ;
F_4 (priv, &xen_9pfs_devs, list) {
if ( ! strcmp ( V_7 -> V_9 , V_5 ) ) {
V_7 -> V_2 = V_2 ;
F_5 ( & V_8 ) ;
return 0 ;
}
}
F_5 ( & V_8 ) ;
return - V_10 ;
}
static void F_6 ( struct V_1 * V_2 )
{
struct V_6 * V_7 ;
F_3 ( & V_8 ) ;
F_4 (priv, &xen_9pfs_devs, list) {
if ( V_7 -> V_2 == V_2 ) {
V_7 -> V_2 = NULL ;
F_5 ( & V_8 ) ;
return;
}
}
F_5 ( & V_8 ) ;
}
static bool F_7 ( struct V_11 * V_12 , T_1 V_13 )
{
T_1 V_14 , V_15 ;
V_14 = V_12 -> V_16 -> V_17 ;
V_15 = V_12 -> V_16 -> V_18 ;
F_8 () ;
return V_19 -
F_9 ( V_15 , V_14 , V_19 ) >= V_13 ;
}
static int F_10 ( struct V_1 * V_2 , struct V_3 * V_20 )
{
struct V_6 * V_7 = NULL ;
T_1 V_14 , V_15 , V_21 , V_22 ;
unsigned long V_23 ;
T_2 V_13 = V_20 -> V_24 -> V_13 ;
struct V_11 * V_12 ;
int V_25 ;
F_3 ( & V_8 ) ;
F_4 (priv, &xen_9pfs_devs, list) {
if ( V_7 -> V_2 == V_2 )
break;
}
F_5 ( & V_8 ) ;
if ( ! V_7 || V_7 -> V_2 != V_2 )
return - V_10 ;
V_25 = V_20 -> V_24 -> V_9 % V_7 -> V_26 ;
V_12 = & V_7 -> V_27 [ V_25 ] ;
V_28:
while ( F_11 ( V_12 -> V_29 ,
F_7 ( V_12 , V_13 ) ) != 0 )
;
F_12 ( & V_12 -> V_30 , V_23 ) ;
V_14 = V_12 -> V_16 -> V_17 ;
V_15 = V_12 -> V_16 -> V_18 ;
F_8 () ;
if ( V_19 - F_9 ( V_15 , V_14 ,
V_19 ) < V_13 ) {
F_13 ( & V_12 -> V_30 , V_23 ) ;
goto V_28;
}
V_22 = F_14 ( V_15 , V_19 ) ;
V_21 = F_14 ( V_14 , V_19 ) ;
F_15 ( V_12 -> V_31 . V_32 , V_20 -> V_24 -> V_33 , V_13 ,
& V_22 , V_21 , V_19 ) ;
V_20 -> V_34 = V_35 ;
F_16 () ;
V_15 += V_13 ;
V_12 -> V_16 -> V_18 = V_15 ;
F_13 ( & V_12 -> V_30 , V_23 ) ;
F_17 ( V_12 -> V_36 ) ;
return 0 ;
}
static void F_18 ( struct V_37 * V_38 )
{
struct V_6 * V_7 ;
struct V_11 * V_12 ;
T_1 V_14 , V_15 , V_21 , V_22 ;
struct V_39 V_40 ;
struct V_3 * V_4 ;
int V_34 ;
V_12 = F_19 ( V_38 , struct V_11 , V_38 ) ;
V_7 = V_12 -> V_7 ;
while ( 1 ) {
V_14 = V_12 -> V_16 -> V_41 ;
V_15 = V_12 -> V_16 -> V_42 ;
F_20 () ;
if ( F_9 ( V_15 , V_14 , V_19 ) <
sizeof( V_40 ) ) {
F_17 ( V_12 -> V_36 ) ;
return;
}
V_22 = F_14 ( V_15 , V_19 ) ;
V_21 = F_14 ( V_14 , V_19 ) ;
F_21 ( & V_40 , V_12 -> V_31 . V_43 , sizeof( V_40 ) ,
V_22 , & V_21 ,
V_19 ) ;
V_4 = F_22 ( V_7 -> V_2 , V_40 . V_9 ) ;
if ( ! V_4 || V_4 -> V_34 != V_35 ) {
F_23 ( & V_7 -> V_44 -> V_44 , L_1 , V_40 . V_9 ) ;
V_14 += V_40 . V_13 ;
F_8 () ;
V_12 -> V_16 -> V_41 = V_14 ;
continue;
}
memcpy ( V_4 -> V_45 , & V_40 , sizeof( V_40 ) ) ;
V_4 -> V_45 -> V_46 = 0 ;
V_21 = F_14 ( V_14 , V_19 ) ;
F_21 ( V_4 -> V_45 -> V_33 , V_12 -> V_31 . V_43 , V_40 . V_13 ,
V_22 , & V_21 ,
V_19 ) ;
F_8 () ;
V_14 += V_40 . V_13 ;
V_12 -> V_16 -> V_41 = V_14 ;
V_34 = ( V_4 -> V_34 != V_47 ) ?
V_48 : V_47 ;
F_24 ( V_7 -> V_2 , V_4 , V_34 ) ;
}
}
static T_3 F_25 ( int V_36 , void * V_49 )
{
struct V_11 * V_12 = V_49 ;
if ( ! V_12 || ! V_12 -> V_7 -> V_2 ) {
return V_50 ;
}
F_26 ( & V_12 -> V_29 ) ;
F_27 ( & V_12 -> V_38 ) ;
return V_50 ;
}
static void F_28 ( struct V_6 * V_7 )
{
int V_51 , V_52 ;
F_29 ( & V_8 ) ;
F_30 ( & V_7 -> V_53 ) ;
F_31 ( & V_8 ) ;
for ( V_51 = 0 ; V_51 < V_7 -> V_26 ; V_51 ++ ) {
if ( ! V_7 -> V_27 [ V_51 ] . V_16 )
break;
if ( V_7 -> V_27 [ V_51 ] . V_36 > 0 )
F_32 ( V_7 -> V_27 [ V_51 ] . V_36 , V_7 -> V_44 ) ;
if ( V_7 -> V_27 [ V_51 ] . V_31 . V_43 ) {
for ( V_52 = 0 ; V_52 < ( 1 << V_54 ) ; V_52 ++ ) {
T_4 V_55 ;
V_55 = V_7 -> V_27 [ V_51 ] . V_16 -> V_55 [ V_52 ] ;
F_33 ( V_55 , 0 , 0 ) ;
}
F_34 ( ( unsigned long ) V_7 -> V_27 [ V_51 ] . V_31 . V_43 ,
V_54 -
( V_56 - V_57 ) ) ;
}
F_33 ( V_7 -> V_27 [ V_51 ] . V_55 , 0 , 0 ) ;
F_35 ( ( unsigned long ) V_7 -> V_27 [ V_51 ] . V_16 ) ;
}
F_36 ( V_7 -> V_27 ) ;
F_36 ( V_7 -> V_9 ) ;
F_36 ( V_7 ) ;
}
static int F_37 ( struct V_58 * V_44 )
{
struct V_6 * V_7 = F_38 ( & V_44 -> V_44 ) ;
F_39 ( & V_44 -> V_44 , NULL ) ;
F_28 ( V_7 ) ;
return 0 ;
}
static int F_40 ( struct V_58 * V_44 ,
struct V_11 * V_12 )
{
int V_51 = 0 ;
int V_59 = - V_60 ;
void * V_61 = NULL ;
F_41 ( & V_12 -> V_29 ) ;
F_42 ( & V_12 -> V_30 ) ;
F_43 ( & V_12 -> V_38 , F_18 ) ;
V_12 -> V_16 = (struct V_62 * ) F_44 ( V_63 ) ;
if ( ! V_12 -> V_16 )
return V_59 ;
V_59 = F_45 ( V_44 -> V_64 ,
F_46 ( V_12 -> V_16 ) , 0 ) ;
if ( V_59 < 0 )
goto V_32;
V_12 -> V_55 = V_59 ;
V_61 = ( void * ) F_47 ( V_63 | V_65 ,
V_54 - ( V_56 - V_57 ) ) ;
if ( ! V_61 ) {
V_59 = - V_60 ;
goto V_32;
}
for (; V_51 < ( 1 << V_54 ) ; V_51 ++ ) {
V_59 = F_45 (
V_44 -> V_64 , F_46 ( V_61 ) + V_51 , 0 ) ;
if ( V_59 < 0 )
goto V_32;
V_12 -> V_16 -> V_55 [ V_51 ] = V_59 ;
}
V_12 -> V_16 -> V_66 = V_54 ;
V_12 -> V_31 . V_43 = V_61 ;
V_12 -> V_31 . V_32 = V_61 + V_19 ;
V_59 = F_48 ( V_44 , & V_12 -> V_67 ) ;
if ( V_59 )
goto V_32;
V_12 -> V_36 = F_49 ( V_12 -> V_67 ,
F_25 ,
0 , L_2 , V_12 ) ;
if ( V_12 -> V_36 >= 0 )
return 0 ;
F_50 ( V_44 , V_12 -> V_67 ) ;
V_59 = V_12 -> V_36 ;
V_32:
if ( V_61 ) {
for ( V_51 -- ; V_51 >= 0 ; V_51 -- )
F_33 ( V_12 -> V_16 -> V_55 [ V_51 ] , 0 , 0 ) ;
F_34 ( ( unsigned long ) V_61 ,
V_54 -
( V_56 - V_57 ) ) ;
}
F_33 ( V_12 -> V_55 , 0 , 0 ) ;
F_35 ( ( unsigned long ) V_12 -> V_16 ) ;
return V_59 ;
}
static int F_51 ( struct V_58 * V_44 ,
const struct V_68 * V_69 )
{
int V_59 , V_51 ;
struct V_70 V_71 ;
struct V_6 * V_7 = NULL ;
char * V_72 ;
unsigned int V_73 , V_74 , V_75 = 0 ;
V_72 = F_52 ( V_76 , V_44 -> V_77 , L_3 , & V_75 ) ;
if ( ! V_75 )
return - V_10 ;
if ( strcmp ( V_72 , L_4 ) ) {
F_36 ( V_72 ) ;
return - V_10 ;
}
F_36 ( V_72 ) ;
V_73 = F_53 ( V_44 -> V_77 , L_5 , 0 ) ;
if ( V_73 < V_78 )
return - V_10 ;
V_74 = F_53 ( V_44 -> V_77 ,
L_6 , 0 ) ;
if ( V_74 < V_54 )
return - V_10 ;
V_7 = F_54 ( sizeof( * V_7 ) , V_63 ) ;
if ( ! V_7 )
return - V_60 ;
V_7 -> V_44 = V_44 ;
V_7 -> V_26 = V_78 ;
V_7 -> V_27 = F_55 ( V_7 -> V_26 , sizeof( * V_7 -> V_27 ) ,
V_63 ) ;
if ( ! V_7 -> V_27 ) {
F_36 ( V_7 ) ;
return - V_60 ;
}
for ( V_51 = 0 ; V_51 < V_7 -> V_26 ; V_51 ++ ) {
V_7 -> V_27 [ V_51 ] . V_7 = V_7 ;
V_59 = F_40 ( V_44 , & V_7 -> V_27 [ V_51 ] ) ;
if ( V_59 < 0 )
goto error;
}
V_28:
V_59 = F_56 ( & V_71 ) ;
if ( V_59 ) {
F_57 ( V_44 , V_59 , L_7 ) ;
goto error;
}
V_59 = F_58 ( V_71 , V_44 -> V_79 , L_8 , L_9 , 1 ) ;
if ( V_59 )
goto V_80;
V_59 = F_58 ( V_71 , V_44 -> V_79 , L_10 , L_9 ,
V_7 -> V_26 ) ;
if ( V_59 )
goto V_80;
for ( V_51 = 0 ; V_51 < V_7 -> V_26 ; V_51 ++ ) {
char V_81 [ 16 ] ;
F_59 ( V_78 > 9 ) ;
sprintf ( V_81 , L_11 , V_51 ) ;
V_59 = F_58 ( V_71 , V_44 -> V_79 , V_81 , L_12 ,
V_7 -> V_27 [ V_51 ] . V_55 ) ;
if ( V_59 )
goto V_80;
sprintf ( V_81 , L_13 , V_51 ) ;
V_59 = F_58 ( V_71 , V_44 -> V_79 , V_81 , L_9 ,
V_7 -> V_27 [ V_51 ] . V_67 ) ;
if ( V_59 )
goto V_80;
}
V_7 -> V_9 = F_52 ( V_71 , V_44 -> V_79 , L_14 , NULL ) ;
if ( F_60 ( V_7 -> V_9 ) ) {
V_59 = F_61 ( V_7 -> V_9 ) ;
goto V_80;
}
V_59 = F_62 ( V_71 , 0 ) ;
if ( V_59 ) {
if ( V_59 == - V_82 )
goto V_28;
F_57 ( V_44 , V_59 , L_15 ) ;
goto error;
}
F_29 ( & V_8 ) ;
F_63 ( & V_7 -> V_53 , & V_83 ) ;
F_31 ( & V_8 ) ;
F_39 ( & V_44 -> V_44 , V_7 ) ;
F_64 ( V_44 , V_84 ) ;
return 0 ;
V_80:
F_62 ( V_71 , 1 ) ;
F_57 ( V_44 , V_59 , L_16 ) ;
error:
F_39 ( & V_44 -> V_44 , NULL ) ;
F_28 ( V_7 ) ;
return V_59 ;
}
static int F_65 ( struct V_58 * V_44 )
{
F_23 ( & V_44 -> V_44 , L_17 ) ;
return 0 ;
}
static void F_66 ( struct V_58 * V_44 ,
enum V_85 V_86 )
{
switch ( V_86 ) {
case V_87 :
case V_88 :
case V_89 :
case V_84 :
case V_90 :
break;
case V_91 :
break;
case V_92 :
F_64 ( V_44 , V_92 ) ;
break;
case V_93 :
if ( V_44 -> V_94 == V_93 )
break;
case V_95 :
F_67 ( V_44 ) ;
break;
}
}
static int F_68 ( void )
{
if ( ! F_69 () )
return - V_96 ;
F_70 ( L_18 ) ;
F_71 ( & V_97 ) ;
return F_72 ( & V_98 ) ;
}
static void F_73 ( void )
{
F_74 ( & V_97 ) ;
return F_75 ( & V_98 ) ;
}
