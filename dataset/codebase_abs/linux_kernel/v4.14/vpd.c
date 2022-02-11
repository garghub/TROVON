static T_1 F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , char * V_7 ,
T_2 V_8 , T_3 V_9 )
{
struct V_10 * V_11 = V_6 -> V_12 ;
return F_2 ( V_7 , V_9 , & V_8 , V_11 -> V_13 ,
V_11 -> V_6 . V_14 ) ;
}
static int F_3 ( const T_4 * V_15 , T_5 V_16 )
{
int V_17 ;
while ( V_16 -- > 0 ) {
V_17 = * V_15 ++ ;
if ( ! isalnum ( V_17 ) && V_17 != '_' )
return V_18 ;
}
return V_19 ;
}
static int F_4 ( const T_4 * V_15 , T_5 V_16 ,
const T_4 * V_13 , T_5 V_20 ,
void * V_21 )
{
int V_22 ;
struct V_23 * V_24 = V_21 ;
struct V_10 * V_11 ;
if ( F_3 ( V_15 , V_16 ) != V_19 )
return V_19 ;
V_11 = F_5 ( sizeof( * V_11 ) , V_25 ) ;
if ( ! V_11 )
return - V_26 ;
V_11 -> V_15 = F_6 ( V_15 , V_16 , V_25 ) ;
if ( ! V_11 -> V_15 ) {
V_22 = - V_26 ;
goto V_27;
}
F_7 ( & V_11 -> V_6 ) ;
V_11 -> V_6 . V_28 . V_29 = V_11 -> V_15 ;
V_11 -> V_6 . V_28 . V_30 = 0444 ;
V_11 -> V_6 . V_14 = V_20 ;
V_11 -> V_6 . V_31 = F_1 ;
V_11 -> V_6 . V_12 = V_11 ;
V_11 -> V_13 = V_13 ;
F_8 ( & V_11 -> V_32 ) ;
V_22 = F_9 ( V_24 -> V_33 , & V_11 -> V_6 ) ;
if ( V_22 )
goto V_34;
F_10 ( & V_11 -> V_32 , & V_24 -> V_35 ) ;
return 0 ;
V_34:
F_11 ( V_11 -> V_15 ) ;
V_27:
F_11 ( V_11 ) ;
return V_22 ;
}
static void F_12 ( struct V_23 * V_24 )
{
struct V_10 * V_11 ;
struct V_10 * V_36 ;
F_13 (info, temp, &sec->attribs, list) {
F_14 ( V_24 -> V_33 , & V_11 -> V_6 ) ;
F_11 ( V_11 -> V_15 ) ;
F_11 ( V_11 ) ;
}
}
static T_1 F_15 ( struct V_1 * V_2 , struct V_3 * V_4 ,
struct V_5 * V_6 , char * V_7 ,
T_2 V_8 , T_3 V_9 )
{
struct V_23 * V_24 = V_6 -> V_12 ;
return F_2 ( V_7 , V_9 , & V_8 , V_24 -> V_37 ,
V_24 -> V_6 . V_14 ) ;
}
static int F_16 ( struct V_23 * V_24 )
{
T_5 V_38 ;
int V_22 ;
V_38 = 0 ;
do {
V_22 = F_17 ( V_24 -> V_6 . V_14 , V_24 -> V_37 ,
& V_38 , F_4 , V_24 ) ;
} while ( V_22 == V_19 );
return 0 ;
}
static int F_18 ( const char * V_29 , struct V_23 * V_24 ,
T_6 V_39 , T_3 V_14 )
{
int V_40 ;
V_24 -> V_37 = F_19 ( V_39 , V_14 , V_41 ) ;
if ( ! V_24 -> V_37 )
return - V_26 ;
V_24 -> V_29 = V_29 ;
V_24 -> V_42 = F_20 ( V_25 , L_1 , V_29 ) ;
if ( ! V_24 -> V_42 ) {
V_40 = - V_26 ;
goto V_43;
}
F_7 ( & V_24 -> V_6 ) ;
V_24 -> V_6 . V_28 . V_29 = V_24 -> V_42 ;
V_24 -> V_6 . V_28 . V_30 = 0444 ;
V_24 -> V_6 . V_14 = V_14 ;
V_24 -> V_6 . V_31 = F_15 ;
V_24 -> V_6 . V_12 = V_24 ;
V_40 = F_9 ( V_44 , & V_24 -> V_6 ) ;
if ( V_40 )
goto V_45;
V_24 -> V_33 = F_21 ( V_29 , V_44 ) ;
if ( ! V_24 -> V_33 ) {
V_40 = - V_46 ;
goto V_47;
}
F_8 ( & V_24 -> V_35 ) ;
F_16 ( V_24 ) ;
V_24 -> V_48 = true ;
return 0 ;
V_47:
F_14 ( V_44 , & V_24 -> V_6 ) ;
V_45:
F_11 ( V_24 -> V_42 ) ;
V_43:
F_22 ( V_24 -> V_37 ) ;
return V_40 ;
}
static int F_23 ( struct V_23 * V_24 )
{
if ( V_24 -> V_48 ) {
F_12 ( V_24 ) ;
F_24 ( V_24 -> V_33 ) ;
F_14 ( V_44 , & V_24 -> V_6 ) ;
F_11 ( V_24 -> V_42 ) ;
F_22 ( V_24 -> V_37 ) ;
}
return 0 ;
}
static int F_25 ( T_6 V_39 )
{
struct V_49 T_7 * V_36 ;
struct V_49 V_50 ;
int V_22 = 0 ;
V_36 = F_19 ( V_39 , sizeof( struct V_49 ) , V_41 ) ;
if ( ! V_36 )
return - V_26 ;
F_26 ( & V_50 , V_36 , sizeof( struct V_49 ) ) ;
F_22 ( V_36 ) ;
if ( V_50 . V_51 != V_52 )
return - V_53 ;
if ( V_50 . V_54 ) {
V_22 = F_18 ( L_2 , & V_55 ,
V_39 + sizeof( struct V_49 ) ,
V_50 . V_54 ) ;
if ( V_22 )
return V_22 ;
}
if ( V_50 . V_56 ) {
V_22 = F_18 ( L_3 , & V_57 ,
V_39 + sizeof( struct V_49 ) +
V_50 . V_54 , V_50 . V_56 ) ;
if ( V_22 )
return V_22 ;
}
return 0 ;
}
static int F_27 ( struct V_58 * V_59 )
{
int V_22 ;
struct V_60 V_61 ;
V_22 = F_28 ( V_62 , & V_61 , sizeof( V_61 ) ) ;
if ( V_22 )
return V_22 ;
return F_25 ( V_61 . V_63 ) ;
}
static int T_8 F_29 ( void )
{
struct V_58 * V_59 ;
V_59 = F_30 ( L_4 , - 1 , NULL , 0 ) ;
if ( F_31 ( V_59 ) )
return F_32 ( V_59 ) ;
V_44 = F_21 ( L_4 , V_64 ) ;
if ( ! V_44 )
return - V_26 ;
F_33 ( & V_65 ) ;
return 0 ;
}
static void T_9 F_34 ( void )
{
F_23 ( & V_55 ) ;
F_23 ( & V_57 ) ;
F_24 ( V_44 ) ;
}
