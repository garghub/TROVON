static int F_1 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_3 * V_4 = V_1 -> V_5 ;
return F_2 ( V_2 , V_4 -> V_6 -> V_7 , V_4 ) ;
}
int F_3 ( const struct V_8 * V_9 , int V_10 ,
struct V_11 * V_12 , struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
struct V_11 * V_17 ;
struct V_3 * V_18 ;
int V_19 , V_20 ;
for ( V_19 = 0 ; V_19 < V_10 ; V_19 ++ ) {
T_1 V_21 = V_9 [ V_19 ] . V_22 ;
if ( V_21 != 0 &&
( V_16 -> V_23 -> V_22 & V_21 ) != V_21 )
continue;
V_18 = F_4 ( sizeof( struct V_3 ) , V_24 ) ;
if ( V_18 == NULL ) {
V_20 = - 1 ;
goto V_25;
}
V_17 = F_5 ( V_9 [ V_19 ] . V_26 , V_27 | V_28 ,
V_12 , V_18 , & V_29 ) ;
if ( ! V_17 ) {
F_6 ( L_1 ,
V_12 , V_9 [ V_19 ] . V_26 ) ;
F_7 ( V_18 ) ;
V_20 = - 1 ;
goto V_25;
}
V_18 -> V_14 = V_14 ;
V_18 -> V_30 = V_17 ;
V_18 -> V_6 = & V_9 [ V_19 ] ;
F_8 ( & V_14 -> V_31 ) ;
F_9 ( & V_18 -> V_32 , & V_14 -> V_33 ) ;
F_10 ( & V_14 -> V_31 ) ;
}
return 0 ;
V_25:
F_11 ( V_9 , V_10 , V_14 ) ;
return V_20 ;
}
int F_12 ( struct V_13 * V_14 , int V_34 ,
struct V_11 * V_12 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
char V_26 [ 64 ] ;
int V_20 ;
F_13 ( & V_14 -> V_33 ) ;
F_14 ( & V_14 -> V_31 ) ;
sprintf ( V_26 , L_2 , V_34 ) ;
V_14 -> V_35 = F_15 ( V_26 , V_12 ) ;
if ( ! V_14 -> V_35 ) {
F_6 ( L_3 , V_26 ) ;
return - 1 ;
}
V_20 = F_3 ( V_36 , V_37 ,
V_14 -> V_35 , V_14 ) ;
if ( V_20 ) {
F_16 ( V_14 -> V_35 ) ;
V_14 -> V_35 = NULL ;
F_6 ( L_4 ) ;
return V_20 ;
}
if ( V_16 -> V_23 -> V_38 ) {
V_20 = V_16 -> V_23 -> V_38 ( V_14 ) ;
if ( V_20 ) {
F_6 ( L_5
L_6 ) ;
return V_20 ;
}
}
return 0 ;
}
int F_11 ( const struct V_8 * V_9 , int V_10 ,
struct V_13 * V_14 )
{
struct V_39 * V_40 , * V_41 ;
struct V_3 * V_18 ;
int V_19 ;
F_8 ( & V_14 -> V_31 ) ;
for ( V_19 = 0 ; V_19 < V_10 ; V_19 ++ ) {
F_17 (pos, q, &minor->debugfs_list) {
V_18 = F_18 ( V_40 , struct V_3 , V_32 ) ;
if ( V_18 -> V_6 == & V_9 [ V_19 ] ) {
F_16 ( V_18 -> V_30 ) ;
F_19 ( V_40 ) ;
F_7 ( V_18 ) ;
}
}
}
F_10 ( & V_14 -> V_31 ) ;
return 0 ;
}
int F_20 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
if ( ! V_14 -> V_35 )
return 0 ;
if ( V_16 -> V_23 -> V_42 )
V_16 -> V_23 -> V_42 ( V_14 ) ;
F_11 ( V_36 , V_37 , V_14 ) ;
F_16 ( V_14 -> V_35 ) ;
V_14 -> V_35 = NULL ;
return 0 ;
}
static int F_21 ( struct V_43 * V_44 , void * V_45 )
{
struct V_46 * V_47 = V_44 -> V_48 ;
const char * V_49 ;
switch ( V_47 -> V_50 ) {
case V_51 :
V_49 = L_7 ;
break;
case V_52 :
V_49 = L_8 ;
break;
case V_53 :
V_49 = L_9 ;
break;
case V_54 :
V_49 = L_10 ;
break;
default:
return 0 ;
}
F_22 ( V_44 , V_49 ) ;
return 0 ;
}
static int F_23 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_46 * V_16 = V_1 -> V_5 ;
return F_2 ( V_2 , F_21 , V_16 ) ;
}
static T_2 F_24 ( struct V_2 * V_2 , const char T_3 * V_55 ,
T_4 V_56 , T_5 * V_57 )
{
struct V_43 * V_44 = V_2 -> V_58 ;
struct V_46 * V_47 = V_44 -> V_48 ;
char V_59 [ 12 ] ;
if ( V_56 > sizeof( V_59 ) - 1 )
return - V_60 ;
if ( F_25 ( V_59 , V_55 , V_56 ) )
return - V_61 ;
V_59 [ V_56 ] = '\0' ;
if ( ! strcmp ( V_59 , L_11 ) )
V_47 -> V_50 = V_51 ;
else if ( ! strcmp ( V_59 , L_12 ) )
V_47 -> V_50 = V_52 ;
else if ( ! strcmp ( V_59 , L_13 ) )
V_47 -> V_50 = V_53 ;
else if ( ! strcmp ( V_59 , L_14 ) )
V_47 -> V_50 = V_54 ;
else
return - V_60 ;
return V_56 ;
}
static int F_26 ( struct V_43 * V_44 , void * V_45 )
{
struct V_46 * V_47 = V_44 -> V_48 ;
struct V_62 * V_63 = V_47 -> V_64 ;
if ( V_47 -> V_65 && V_63 )
F_27 ( V_44 , V_63 -> V_45 , V_63 -> V_66 ) ;
return 0 ;
}
static int F_28 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_46 * V_16 = V_1 -> V_5 ;
return F_2 ( V_2 , F_26 , V_16 ) ;
}
static T_2 F_29 ( struct V_2 * V_2 , const char T_3 * V_55 ,
T_4 V_56 , T_5 * V_57 )
{
struct V_43 * V_44 = V_2 -> V_58 ;
struct V_46 * V_47 = V_44 -> V_48 ;
char * V_59 ;
struct V_63 * V_63 ;
int V_20 ;
V_59 = F_30 ( V_55 , V_56 ) ;
if ( F_31 ( V_59 ) )
return F_32 ( V_59 ) ;
V_63 = (struct V_63 * ) V_59 ;
if ( V_56 == 5 && ! strncmp ( V_59 , L_15 , 5 ) ) {
V_47 -> V_65 = false ;
V_20 = F_33 ( V_47 , NULL ) ;
} else if ( V_56 < V_67 ||
V_67 * ( 1 + V_63 -> V_68 ) > V_56 )
V_20 = - V_60 ;
else {
V_47 -> V_65 = false ;
V_20 = F_33 ( V_47 , V_63 ) ;
if ( ! V_20 )
V_47 -> V_65 = true ;
}
F_7 ( V_59 ) ;
return ( V_20 ) ? V_20 : V_56 ;
}
int F_34 ( struct V_46 * V_47 )
{
struct V_13 * V_14 = V_47 -> V_16 -> V_69 ;
struct V_11 * V_12 , * V_17 ;
if ( ! V_14 -> V_35 )
return - 1 ;
V_12 = F_15 ( V_47 -> V_26 , V_14 -> V_35 ) ;
if ( ! V_12 )
return - V_70 ;
V_47 -> V_71 = V_12 ;
V_17 = F_5 ( L_16 , V_28 | V_72 , V_12 , V_47 ,
& V_73 ) ;
if ( ! V_17 )
goto error;
V_17 = F_5 ( L_17 , V_28 | V_72 , V_12 ,
V_47 , & V_74 ) ;
if ( ! V_17 )
goto error;
return 0 ;
error:
F_35 ( V_47 -> V_71 ) ;
V_47 -> V_71 = NULL ;
return - V_70 ;
}
void F_36 ( struct V_46 * V_47 )
{
if ( ! V_47 -> V_71 )
return;
F_35 ( V_47 -> V_71 ) ;
V_47 -> V_71 = NULL ;
}
