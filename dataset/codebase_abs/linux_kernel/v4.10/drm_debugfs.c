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
if ( F_17 ( V_16 , V_38 ) ) {
V_20 = F_18 ( V_14 ) ;
if ( V_20 ) {
F_6 ( L_5 ) ;
return V_20 ;
}
}
if ( V_16 -> V_23 -> V_39 ) {
V_20 = V_16 -> V_23 -> V_39 ( V_14 ) ;
if ( V_20 ) {
F_6 ( L_6
L_7 ) ;
return V_20 ;
}
}
return 0 ;
}
int F_11 ( const struct V_8 * V_9 , int V_10 ,
struct V_13 * V_14 )
{
struct V_40 * V_41 , * V_42 ;
struct V_3 * V_18 ;
int V_19 ;
F_8 ( & V_14 -> V_31 ) ;
for ( V_19 = 0 ; V_19 < V_10 ; V_19 ++ ) {
F_19 (pos, q, &minor->debugfs_list) {
V_18 = F_20 ( V_41 , struct V_3 , V_32 ) ;
if ( V_18 -> V_6 == & V_9 [ V_19 ] ) {
F_16 ( V_18 -> V_30 ) ;
F_21 ( V_41 ) ;
F_7 ( V_18 ) ;
}
}
}
F_10 ( & V_14 -> V_31 ) ;
return 0 ;
}
int F_22 ( struct V_13 * V_14 )
{
struct V_15 * V_16 = V_14 -> V_16 ;
int V_20 ;
if ( ! V_14 -> V_35 )
return 0 ;
if ( V_16 -> V_23 -> V_43 )
V_16 -> V_23 -> V_43 ( V_14 ) ;
if ( F_17 ( V_16 , V_38 ) ) {
V_20 = F_23 ( V_14 ) ;
if ( V_20 ) {
F_6 ( L_8 ) ;
return V_20 ;
}
}
F_11 ( V_36 , V_37 , V_14 ) ;
F_16 ( V_14 -> V_35 ) ;
V_14 -> V_35 = NULL ;
return 0 ;
}
static int F_24 ( struct V_44 * V_45 , void * V_46 )
{
struct V_47 * V_48 = V_45 -> V_49 ;
const char * V_50 ;
switch ( V_48 -> V_51 ) {
case V_52 :
V_50 = L_9 ;
break;
case V_53 :
V_50 = L_10 ;
break;
case V_54 :
V_50 = L_11 ;
break;
case V_55 :
V_50 = L_12 ;
break;
default:
return 0 ;
}
F_25 ( V_45 , V_50 ) ;
return 0 ;
}
static int F_26 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_47 * V_16 = V_1 -> V_5 ;
return F_2 ( V_2 , F_24 , V_16 ) ;
}
static T_2 F_27 ( struct V_2 * V_2 , const char T_3 * V_56 ,
T_4 V_57 , T_5 * V_58 )
{
struct V_44 * V_45 = V_2 -> V_59 ;
struct V_47 * V_48 = V_45 -> V_49 ;
char V_60 [ 12 ] ;
if ( V_57 > sizeof( V_60 ) - 1 )
return - V_61 ;
if ( F_28 ( V_60 , V_56 , V_57 ) )
return - V_62 ;
V_60 [ V_57 ] = '\0' ;
if ( ! strcmp ( V_60 , L_13 ) )
V_48 -> V_51 = V_52 ;
else if ( ! strcmp ( V_60 , L_14 ) )
V_48 -> V_51 = V_53 ;
else if ( ! strcmp ( V_60 , L_15 ) )
V_48 -> V_51 = V_54 ;
else if ( ! strcmp ( V_60 , L_16 ) )
V_48 -> V_51 = V_55 ;
else
return - V_61 ;
return V_57 ;
}
static int F_29 ( struct V_44 * V_45 , void * V_46 )
{
struct V_47 * V_48 = V_45 -> V_49 ;
struct V_63 * V_64 = V_48 -> V_65 ;
if ( V_48 -> V_66 && V_64 )
F_30 ( V_45 , V_64 -> V_46 , V_64 -> V_67 ) ;
return 0 ;
}
static int F_31 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_47 * V_16 = V_1 -> V_5 ;
return F_2 ( V_2 , F_29 , V_16 ) ;
}
static T_2 F_32 ( struct V_2 * V_2 , const char T_3 * V_56 ,
T_4 V_57 , T_5 * V_58 )
{
struct V_44 * V_45 = V_2 -> V_59 ;
struct V_47 * V_48 = V_45 -> V_49 ;
char * V_60 ;
struct V_64 * V_64 ;
int V_20 ;
V_60 = F_33 ( V_56 , V_57 ) ;
if ( F_34 ( V_60 ) )
return F_35 ( V_60 ) ;
V_64 = (struct V_64 * ) V_60 ;
if ( V_57 == 5 && ! strncmp ( V_60 , L_17 , 5 ) ) {
V_48 -> V_66 = false ;
V_20 = F_36 ( V_48 , NULL ) ;
} else if ( V_57 < V_68 ||
V_68 * ( 1 + V_64 -> V_69 ) > V_57 )
V_20 = - V_61 ;
else {
V_48 -> V_66 = false ;
V_20 = F_36 ( V_48 , V_64 ) ;
if ( ! V_20 )
V_48 -> V_66 = true ;
}
F_7 ( V_60 ) ;
return ( V_20 ) ? V_20 : V_57 ;
}
int F_37 ( struct V_47 * V_48 )
{
struct V_13 * V_14 = V_48 -> V_16 -> V_70 ;
struct V_11 * V_12 , * V_17 ;
if ( ! V_14 -> V_35 )
return - 1 ;
V_12 = F_15 ( V_48 -> V_26 , V_14 -> V_35 ) ;
if ( ! V_12 )
return - V_71 ;
V_48 -> V_72 = V_12 ;
V_17 = F_5 ( L_18 , V_28 | V_73 , V_12 , V_48 ,
& V_74 ) ;
if ( ! V_17 )
goto error;
V_17 = F_5 ( L_19 , V_28 | V_73 , V_12 ,
V_48 , & V_75 ) ;
if ( ! V_17 )
goto error;
return 0 ;
error:
F_38 ( V_48 -> V_72 ) ;
V_48 -> V_72 = NULL ;
return - V_71 ;
}
void F_39 ( struct V_47 * V_48 )
{
if ( ! V_48 -> V_72 )
return;
F_38 ( V_48 -> V_72 ) ;
V_48 -> V_72 = NULL ;
}
int F_40 ( struct V_76 * V_77 )
{
struct V_13 * V_14 = V_77 -> V_16 -> V_70 ;
struct V_11 * V_12 ;
char * V_26 ;
V_26 = F_41 ( V_24 , L_20 , V_77 -> V_78 ) ;
if ( ! V_26 )
return - V_71 ;
V_12 = F_15 ( V_26 , V_14 -> V_35 ) ;
F_7 ( V_26 ) ;
if ( ! V_12 )
return - V_71 ;
V_77 -> V_72 = V_12 ;
if ( F_42 ( V_77 ) )
goto error;
return 0 ;
error:
F_43 ( V_77 ) ;
return - V_71 ;
}
void F_43 ( struct V_76 * V_77 )
{
F_38 ( V_77 -> V_72 ) ;
V_77 -> V_72 = NULL ;
}
