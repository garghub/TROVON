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
static void F_22 ( struct V_13 * V_14 )
{
struct V_3 * V_4 , * V_18 ;
F_8 ( & V_14 -> V_31 ) ;
F_23 (node, tmp, &minor->debugfs_list, list) {
F_16 ( V_4 -> V_30 ) ;
F_21 ( & V_4 -> V_32 ) ;
F_7 ( V_4 ) ;
}
F_10 ( & V_14 -> V_31 ) ;
}
int F_24 ( struct V_13 * V_14 )
{
if ( ! V_14 -> V_35 )
return 0 ;
F_22 ( V_14 ) ;
F_25 ( V_14 -> V_35 ) ;
V_14 -> V_35 = NULL ;
return 0 ;
}
static int F_26 ( struct V_43 * V_44 , void * V_45 )
{
struct V_46 * V_47 = V_44 -> V_48 ;
F_27 ( V_44 , L_8 , F_28 ( V_47 -> V_49 ) ) ;
return 0 ;
}
static int F_29 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_46 * V_16 = V_1 -> V_5 ;
return F_2 ( V_2 , F_26 , V_16 ) ;
}
static T_2 F_30 ( struct V_2 * V_2 , const char T_3 * V_50 ,
T_4 V_51 , T_5 * V_52 )
{
struct V_43 * V_44 = V_2 -> V_53 ;
struct V_46 * V_47 = V_44 -> V_48 ;
char V_54 [ 12 ] ;
if ( V_51 > sizeof( V_54 ) - 1 )
return - V_55 ;
if ( F_31 ( V_54 , V_50 , V_51 ) )
return - V_56 ;
V_54 [ V_51 ] = '\0' ;
if ( ! strcmp ( V_54 , L_9 ) )
V_47 -> V_49 = V_57 ;
else if ( ! strcmp ( V_54 , L_10 ) )
V_47 -> V_49 = V_58 ;
else if ( ! strcmp ( V_54 , L_11 ) )
V_47 -> V_49 = V_59 ;
else if ( ! strcmp ( V_54 , L_12 ) )
V_47 -> V_49 = V_60 ;
else
return - V_55 ;
return V_51 ;
}
static int F_32 ( struct V_43 * V_44 , void * V_45 )
{
struct V_46 * V_47 = V_44 -> V_48 ;
struct V_61 * V_62 = V_47 -> V_63 ;
if ( V_47 -> V_64 && V_62 )
F_33 ( V_44 , V_62 -> V_45 , V_62 -> V_65 ) ;
return 0 ;
}
static int F_34 ( struct V_1 * V_1 , struct V_2 * V_2 )
{
struct V_46 * V_16 = V_1 -> V_5 ;
return F_2 ( V_2 , F_32 , V_16 ) ;
}
static T_2 F_35 ( struct V_2 * V_2 , const char T_3 * V_50 ,
T_4 V_51 , T_5 * V_52 )
{
struct V_43 * V_44 = V_2 -> V_53 ;
struct V_46 * V_47 = V_44 -> V_48 ;
char * V_54 ;
struct V_62 * V_62 ;
int V_20 ;
V_54 = F_36 ( V_50 , V_51 ) ;
if ( F_37 ( V_54 ) )
return F_38 ( V_54 ) ;
V_62 = (struct V_62 * ) V_54 ;
if ( V_51 == 5 && ! strncmp ( V_54 , L_13 , 5 ) ) {
V_47 -> V_64 = false ;
V_20 = F_39 ( V_47 , NULL ) ;
} else if ( V_51 < V_66 ||
V_66 * ( 1 + V_62 -> V_67 ) > V_51 )
V_20 = - V_55 ;
else {
V_47 -> V_64 = false ;
V_20 = F_39 ( V_47 , V_62 ) ;
if ( ! V_20 )
V_47 -> V_64 = true ;
}
F_7 ( V_54 ) ;
return ( V_20 ) ? V_20 : V_51 ;
}
int F_40 ( struct V_46 * V_47 )
{
struct V_13 * V_14 = V_47 -> V_16 -> V_68 ;
struct V_11 * V_12 , * V_17 ;
if ( ! V_14 -> V_35 )
return - 1 ;
V_12 = F_15 ( V_47 -> V_26 , V_14 -> V_35 ) ;
if ( ! V_12 )
return - V_69 ;
V_47 -> V_70 = V_12 ;
V_17 = F_5 ( L_14 , V_28 | V_71 , V_12 , V_47 ,
& V_72 ) ;
if ( ! V_17 )
goto error;
V_17 = F_5 ( L_15 , V_28 | V_71 , V_12 ,
V_47 , & V_73 ) ;
if ( ! V_17 )
goto error;
return 0 ;
error:
F_25 ( V_47 -> V_70 ) ;
V_47 -> V_70 = NULL ;
return - V_69 ;
}
void F_41 ( struct V_46 * V_47 )
{
if ( ! V_47 -> V_70 )
return;
F_25 ( V_47 -> V_70 ) ;
V_47 -> V_70 = NULL ;
}
int F_42 ( struct V_74 * V_75 )
{
struct V_13 * V_14 = V_75 -> V_16 -> V_68 ;
struct V_11 * V_12 ;
char * V_26 ;
V_26 = F_43 ( V_24 , L_16 , V_75 -> V_76 ) ;
if ( ! V_26 )
return - V_69 ;
V_12 = F_15 ( V_26 , V_14 -> V_35 ) ;
F_7 ( V_26 ) ;
if ( ! V_12 )
return - V_69 ;
V_75 -> V_70 = V_12 ;
if ( F_44 ( V_75 ) )
goto error;
return 0 ;
error:
F_45 ( V_75 ) ;
return - V_69 ;
}
void F_45 ( struct V_74 * V_75 )
{
F_25 ( V_75 -> V_70 ) ;
V_75 -> V_70 = NULL ;
}
