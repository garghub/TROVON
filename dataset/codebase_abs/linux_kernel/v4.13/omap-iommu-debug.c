static inline bool F_1 ( struct V_1 * V_2 )
{
return ! V_2 -> V_3 ;
}
static T_1
F_2 ( struct V_1 * V_2 , char * V_4 , T_1 V_5 )
{
char * V_6 = V_4 ;
F_3 ( V_7 ) ;
F_3 ( V_8 ) ;
F_3 ( V_9 ) ;
F_3 ( V_10 ) ;
F_3 ( V_11 ) ;
F_3 ( V_12 ) ;
F_3 ( V_13 ) ;
F_3 ( V_14 ) ;
F_3 ( V_15 ) ;
F_3 ( V_16 ) ;
F_3 ( V_17 ) ;
F_3 ( V_18 ) ;
F_3 ( V_19 ) ;
F_3 ( V_20 ) ;
F_3 ( V_21 ) ;
F_3 ( V_22 ) ;
V_23:
return V_6 - V_4 ;
}
static T_1 F_4 ( struct V_1 * V_2 , char * V_4 ,
T_1 V_24 )
{
if ( ! V_2 || ! V_4 )
return - V_25 ;
F_5 ( V_2 -> V_26 ) ;
V_24 = F_2 ( V_2 , V_4 , V_24 ) ;
F_6 ( V_2 -> V_26 ) ;
return V_24 ;
}
static T_1 F_7 ( struct V_27 * V_27 , char T_2 * V_28 ,
T_3 V_29 , T_4 * V_30 )
{
struct V_1 * V_2 = V_27 -> V_31 ;
char * V_6 , * V_4 ;
T_1 V_24 ;
if ( F_1 ( V_2 ) )
return - V_32 ;
V_4 = F_8 ( V_29 , V_33 ) ;
if ( ! V_4 )
return - V_34 ;
V_6 = V_4 ;
F_9 ( & V_35 ) ;
V_24 = F_4 ( V_2 , V_6 , V_29 ) ;
V_24 = F_10 ( V_28 , V_29 , V_30 , V_4 , V_24 ) ;
F_11 ( & V_35 ) ;
F_12 ( V_4 ) ;
return V_24 ;
}
static int
F_13 ( struct V_1 * V_2 , struct V_36 * V_37 , int V_38 )
{
int V_39 ;
struct V_40 V_41 ;
struct V_36 V_42 ;
struct V_36 * V_6 = V_37 ;
F_5 ( V_2 -> V_26 ) ;
F_14 ( V_2 , & V_41 ) ;
F_15 (obj, num, i, tmp) {
if ( ! F_16 ( & V_42 ) )
continue;
* V_6 ++ = V_42 ;
}
F_17 ( V_2 , & V_41 ) ;
F_6 ( V_2 -> V_26 ) ;
return V_6 - V_37 ;
}
static T_1 F_18 ( struct V_1 * V_2 , struct V_36 * V_43 ,
struct V_44 * V_45 )
{
F_19 ( V_45 , L_1 , V_43 -> V_46 , V_43 -> V_47 ,
( V_43 -> V_46 & V_48 ) ? 1 : 0 ) ;
return 0 ;
}
static T_3 F_20 ( struct V_1 * V_2 , struct V_44 * V_45 )
{
int V_39 , V_38 ;
struct V_36 * V_43 ;
V_38 = V_2 -> V_49 ;
V_43 = F_21 ( V_38 , sizeof( * V_43 ) , V_33 ) ;
if ( ! V_43 )
return 0 ;
V_38 = F_13 ( V_2 , V_43 , V_38 ) ;
for ( V_39 = 0 ; V_39 < V_38 ; V_39 ++ )
F_18 ( V_2 , V_43 + V_39 , V_45 ) ;
F_12 ( V_43 ) ;
return 0 ;
}
static int F_22 ( struct V_44 * V_45 , void * V_50 )
{
struct V_1 * V_2 = V_45 -> V_51 ;
if ( F_1 ( V_2 ) )
return - V_32 ;
F_9 ( & V_35 ) ;
F_19 ( V_45 , L_2 , L_3 , L_4 ) ;
F_23 ( V_45 , L_5 ) ;
F_20 ( V_2 , V_45 ) ;
F_11 ( & V_35 ) ;
return 0 ;
}
static void F_24 ( struct V_44 * V_45 )
{
int V_39 , V_52 ;
T_5 V_53 ;
T_5 * V_54 , * V_55 ;
struct V_1 * V_2 = V_45 -> V_51 ;
F_25 ( & V_2 -> V_56 ) ;
V_54 = F_26 ( V_2 , 0 ) ;
for ( V_39 = 0 ; V_39 < V_57 ; V_39 ++ , V_54 ++ ) {
if ( ! * V_54 )
continue;
if ( ! ( * V_54 & V_58 ) ) {
V_53 = V_39 << V_59 ;
F_19 ( V_45 , L_6 , V_53 , * V_54 ) ;
continue;
}
V_55 = F_27 ( V_54 , 0 ) ;
for ( V_52 = 0 ; V_52 < V_60 ; V_52 ++ , V_55 ++ ) {
if ( ! * V_55 )
continue;
V_53 = ( V_39 << V_59 ) + ( V_52 << V_61 ) ;
F_19 ( V_45 , L_7 , V_53 , * V_55 ) ;
}
}
F_28 ( & V_2 -> V_56 ) ;
}
static int F_29 ( struct V_44 * V_45 , void * V_50 )
{
struct V_1 * V_2 = V_45 -> V_51 ;
if ( F_1 ( V_2 ) )
return - V_32 ;
F_9 ( & V_35 ) ;
F_19 ( V_45 , L_8 , L_9 , L_10 ) ;
F_23 ( V_45 , L_11 ) ;
F_24 ( V_45 ) ;
F_11 ( & V_35 ) ;
return 0 ;
}
void F_30 ( struct V_1 * V_2 )
{
struct V_62 * V_63 ;
if ( ! V_64 )
return;
V_2 -> V_65 = F_31 ( V_2 -> V_66 , V_64 ) ;
if ( ! V_2 -> V_65 )
return;
V_63 = F_32 ( L_12 , 0400 , V_2 -> V_65 ,
( V_67 * ) & V_2 -> V_49 ) ;
if ( ! V_63 )
return;
F_33 ( V_68 ) ;
F_33 ( V_69 ) ;
F_33 ( V_70 ) ;
return;
V_71:
F_34 ( V_2 -> V_65 ) ;
}
void F_35 ( struct V_1 * V_2 )
{
if ( ! V_2 -> V_65 )
return;
F_34 ( V_2 -> V_65 ) ;
}
void T_6 F_36 ( void )
{
V_64 = F_31 ( L_13 , NULL ) ;
if ( ! V_64 )
F_37 ( L_14 ) ;
}
void T_7 F_38 ( void )
{
F_39 ( V_64 ) ;
}
