static void F_1 ( struct V_1 * V_2 ,
int V_3 )
{
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
struct V_6 * V_7 = V_5 -> V_8 ;
F_3 ( V_7 -> V_9 , V_2 ) ;
F_4 ( V_5 -> V_10 ) ;
F_5 ( V_7 -> V_9 -> V_11 . V_12 , V_5 ) ;
}
static T_1 int F_6 ( struct V_13 * V_14 ,
struct V_4 * V_5 )
{
int V_15 , V_16 = 0 ;
V_16 = F_7 (
V_14 -> V_9 ,
& V_5 -> V_2 ,
V_5 -> V_10 -> V_17 ,
F_8 ( V_5 -> V_10 ) ) ;
if ( F_9 ( V_16 ) )
goto V_18;
for ( V_15 = 0 ; V_15 < F_10 ( V_5 -> V_10 ) -> V_19 ; V_15 ++ ) {
struct V_20 * V_21 = & F_10 ( V_5 -> V_10 ) -> V_22 [ V_15 ] ;
V_16 = F_11 ( V_14 -> V_9 ,
& V_5 -> V_2 ,
F_12 ( V_21 ) ,
V_21 -> V_23 ,
F_13 ( V_21 ) ) ;
if ( F_9 ( V_16 ) )
goto V_18;
}
if ( V_5 -> V_24 )
V_16 = F_7 ( V_14 -> V_9 , & V_5 -> V_2 ,
V_5 -> V_25 + V_26 - V_5 -> V_24 ,
V_5 -> V_24 ) ;
V_18:
return V_16 ;
}
static int F_14 ( struct V_13 * V_14 ,
struct V_4 * V_5 ,
T_2 V_27 )
{
int V_16 = 0 ;
T_3 V_28 = 2 << 2 ;
V_16 = F_15 (
& V_5 -> V_2 ,
0 ,
V_28 + V_5 -> V_10 -> V_29 + V_5 -> V_24 ,
0 ,
0 ,
NULL ,
0 ,
F_1 ) ;
if ( F_9 ( V_16 ) )
goto V_18;
V_5 -> V_30 = F_16 ( V_27 ) ;
V_16 = F_7 (
V_14 -> V_9 ,
& V_5 -> V_2 ,
& V_5 -> V_30 ,
V_28 ) ;
if ( F_9 ( V_16 ) )
goto V_18;
V_16 = F_6 ( V_14 , V_5 ) ;
V_18:
return V_16 ;
}
static inline void F_17 ( unsigned char * V_25 , T_4 V_24 )
{
V_25 [ V_26 - 1 ] = V_24 - V_31 ;
}
int F_18 ( struct V_32 * V_9 , T_4 V_33 ,
struct V_34 * V_35 ,
struct V_36 * V_10 , T_2 V_27 , T_4 V_24 )
{
struct V_6 * V_7 = & V_35 -> V_8 [ V_33 ] ;
struct V_13 * V_14 = V_7 -> V_14 ;
struct V_4 * V_5 ;
int V_16 = - V_37 ;
if ( F_9 ( F_19 ( V_7 -> V_38 ) != V_39 ) )
goto V_40;
if ( F_9 ( ! V_14 || ! F_20 ( V_14 ) ) )
goto V_40;
V_5 = F_21 ( V_9 -> V_11 . V_12 , V_41 ) ;
if ( F_9 ( ! V_5 ) ) {
V_16 = - V_42 ;
goto V_40;
}
V_5 -> V_8 = V_7 ;
V_5 -> V_10 = V_10 ;
F_17 ( V_5 -> V_25 , V_24 ) ;
V_5 -> V_24 = V_24 ;
V_16 = F_14 ( V_14 , V_5 , V_27 ) ;
if ( F_9 ( V_16 ) )
goto V_43;
V_5 -> V_44 = 0 ;
V_16 = F_22 ( V_14 , & V_7 -> V_45 , & V_5 -> V_2 ) ;
if ( F_9 ( V_16 && F_9 ( V_16 != - V_37 ) ) )
goto V_43;
return V_16 ;
V_43:
F_3 ( V_9 , & V_5 -> V_2 ) ;
F_5 ( V_9 -> V_11 . V_12 , V_5 ) ;
V_40:
if ( V_16 != - V_46 )
F_4 ( V_10 ) ;
return V_16 ;
}
static int F_23 ( struct V_13 * V_14 ,
struct V_47 * V_45 ,
struct V_1 * V_2 ,
unsigned int V_48 )
{
struct V_6 * V_7 =
F_2 ( V_45 , struct V_6 , V_45 ) ;
struct V_49 * V_50 = & V_7 -> V_9 -> V_51 ;
struct V_4 * V_5 = F_2 ( V_2 , struct V_4 , V_2 ) ;
if ( F_24 ( V_14 , V_48 , V_2 ) )
if ( V_5 -> V_44 ++ < V_52 )
return - V_53 ;
V_7 -> V_38 = V_54 ;
F_25 ( & V_50 -> V_55 ) ;
if ( F_26 ( & V_7 -> V_45 . V_56 ) )
F_27 ( & V_7 -> V_45 . V_56 , & V_14 -> V_57 ) ;
F_28 ( & V_50 -> V_55 ) ;
return - V_46 ;
}
static void F_29 ( struct V_47 * V_45 , int V_58 )
{
struct V_6 * V_7 =
F_2 ( V_45 , struct V_6 , V_45 ) ;
struct V_34 * V_35 = V_7 -> V_35 ;
V_7 -> V_38 = V_39 ;
if ( F_30 ( V_35 -> V_59 , V_7 -> V_33 ) )
F_31 ( V_35 -> V_59 , V_7 -> V_33 ) ;
}
inline bool F_32 ( struct V_34 * V_35 ,
T_4 V_33 )
{
struct V_6 * V_7 = & V_35 -> V_8 [ V_33 ] ;
return ( F_19 ( V_7 -> V_38 ) == V_39 ) ;
}
void F_33 ( struct V_34 * V_35 )
{
int V_15 ;
for ( V_15 = 0 ; V_15 < V_35 -> V_60 ; V_15 ++ ) {
struct V_6 * V_7 = & V_35 -> V_8 [ V_15 ] ;
F_34 ( & V_7 -> V_45 , 0 , NULL , F_23 ,
F_29 , NULL ) ;
V_7 -> V_14 = & V_35 -> V_9 -> V_61 [ V_15 ] ;
V_7 -> V_9 = V_35 -> V_9 ;
V_7 -> V_35 = V_35 ;
V_7 -> V_33 = V_15 ;
V_7 -> V_38 = V_39 ;
if ( V_7 -> V_14 -> V_62 > V_63 ) {
F_35 ( & V_7 -> V_64 . V_56 ) ;
V_7 -> V_64 . V_65 = V_63 ;
F_27 ( & V_7 -> V_64 . V_56 ,
& V_7 -> V_45 . V_66 ) ;
}
}
}
static void F_36 ( void * V_67 )
{
struct V_4 * V_5 = (struct V_4 * ) V_67 ;
memset ( V_5 , 0 , sizeof( * V_5 ) ) ;
}
int F_37 ( struct V_32 * V_9 )
{
char V_68 [ V_69 ] ;
snprintf ( V_68 , sizeof( V_68 ) , L_1 , V_9 -> V_70 ) ;
V_9 -> V_11 . V_12 = F_38 ( V_68 ,
sizeof( struct V_4 ) ,
0 , V_71 ,
F_36 ) ;
if ( ! V_9 -> V_11 . V_12 )
return - V_42 ;
return 0 ;
}
void F_39 ( struct V_32 * V_9 )
{
F_40 ( V_9 -> V_11 . V_12 ) ;
V_9 -> V_11 . V_12 = NULL ;
}
