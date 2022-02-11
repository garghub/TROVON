static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , int V_5 )
{
int V_6 ;
V_6 = F_2 ( & V_4 -> V_7 ) ;
if ( V_6 < 0 )
return V_6 ;
F_3 ( V_2 , L_1 , V_5 ) ;
V_6 = F_4 ( V_4 -> V_8 , V_5 ) ;
F_5 ( & V_4 -> V_7 ) ;
return V_6 ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_9 * V_10 , char * V_11 )
{
struct V_3 * V_12 = F_7 ( F_8 ( V_2 ) ) ;
struct V_13 * V_14 = F_9 ( V_10 ) ;
int V_6 ;
V_6 = F_1 ( V_2 , V_12 , V_14 -> V_15 ) ;
return ( V_6 < 0 ) ? V_6 : snprintf ( V_11 , V_16 , L_2 , V_6 ) ;
}
static inline int F_10 ( struct V_1 * V_2 )
{
return F_11 ( & V_2 -> V_17 , & V_18 ) ;
}
static inline void F_12 ( struct V_1 * V_2 )
{
F_13 ( & V_2 -> V_17 , & V_18 ) ;
}
static inline int F_10 ( struct V_1 * V_2 ) { return 0 ; }
static inline void F_12 ( struct V_1 * V_2 ) { }
static T_1 F_14 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
char * V_11 )
{
struct V_13 * V_19 = F_9 ( V_10 ) ;
struct V_3 * V_4 = F_7 ( F_8 ( V_2 ) ) ;
struct V_20 * V_21 = F_15 ( V_2 ) ;
struct V_22 * V_23 ;
int V_6 ;
V_23 = V_21 -> V_24 [ V_19 -> V_15 ] ;
V_6 = F_1 ( V_2 , V_4 , V_19 -> V_15 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 *= V_23 -> V_25 ;
V_6 = F_16 ( V_6 , V_23 -> div ) ;
return snprintf ( V_11 , V_16 , L_2 , V_6 ) ;
}
static T_1 F_17 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
char * V_11 )
{
struct V_13 * V_19 = F_9 ( V_10 ) ;
struct V_20 * V_21 = F_15 ( V_2 ) ;
struct V_22 * V_23 ;
V_23 = V_21 -> V_24 [ V_19 -> V_15 ] ;
return snprintf ( V_11 , V_16 , L_3 , V_23 -> V_26 ) ;
}
static int F_18 ( struct V_1 * V_2 ,
struct V_22 * V_23 ,
struct V_27 * V_28 ,
int V_5 )
{
struct V_13 * V_10 ;
int V_6 ;
snprintf ( V_28 -> V_29 , sizeof( V_28 -> V_29 ) , L_4 , V_5 ) ;
V_10 = & V_28 -> V_24 ;
V_10 -> V_15 = V_5 ;
F_19 ( & V_10 -> V_30 . V_10 ) ;
V_10 -> V_30 . V_10 . V_26 = V_28 -> V_29 ;
V_10 -> V_30 . V_10 . V_31 = V_32 ;
V_10 -> V_30 . V_33 = F_14 ;
V_6 = F_20 ( V_2 , & V_10 -> V_30 ) ;
if ( V_6 < 0 ) {
F_21 ( V_2 , L_5 ) ;
return V_6 ;
}
if ( V_23 -> V_26 ) {
snprintf ( V_28 -> V_34 , sizeof( V_28 -> V_34 ) ,
L_6 , V_5 ) ;
V_10 = & V_28 -> V_35 ;
V_10 -> V_15 = V_5 ;
F_19 ( & V_10 -> V_30 . V_10 ) ;
V_10 -> V_30 . V_10 . V_26 = V_28 -> V_34 ;
V_10 -> V_30 . V_10 . V_31 = V_32 ;
V_10 -> V_30 . V_33 = F_17 ;
V_6 = F_20 ( V_2 , & V_10 -> V_30 ) ;
if ( V_6 < 0 ) {
F_22 ( V_2 , & V_28 -> V_24 . V_30 ) ;
F_21 ( V_2 , L_7 ) ;
}
}
return V_6 ;
}
static void F_23 ( struct V_1 * V_2 ,
struct V_27 * V_28 )
{
F_22 ( V_2 , & V_28 -> V_24 . V_30 ) ;
F_22 ( V_2 , & V_28 -> V_35 . V_30 ) ;
}
static int F_24 ( struct V_36 * V_2 )
{
struct V_20 * V_21 = F_15 ( & V_2 -> V_2 ) ;
struct V_3 * V_4 ;
int V_6 = 0 ;
int V_37 ;
if ( ! V_21 ) {
F_21 ( & V_2 -> V_2 , L_8 ) ;
return - V_38 ;
}
V_4 = F_25 ( & V_2 -> V_2 , sizeof( struct V_3 ) , V_39 ) ;
if ( V_4 == NULL )
return - V_40 ;
F_26 ( V_2 , V_4 ) ;
F_27 ( & V_4 -> V_7 ) ;
V_4 -> V_8 = F_28 ( V_2 , NULL , NULL , 0 ) ;
if ( F_29 ( V_4 -> V_8 ) ) {
F_21 ( & V_2 -> V_2 , L_9 ) ;
return F_30 ( V_4 -> V_8 ) ;
}
V_6 = F_10 ( & V_2 -> V_2 ) ;
if ( V_6 )
goto V_41;
V_4 -> V_42 = F_31 ( & V_2 -> V_2 ) ;
if ( F_29 ( V_4 -> V_42 ) ) {
F_21 ( & V_2 -> V_2 , L_10 ) ;
V_6 = F_30 ( V_4 -> V_42 ) ;
goto V_43;
}
for ( V_37 = 0 ; V_37 < F_32 ( V_21 -> V_24 ) ; V_37 ++ ) {
struct V_22 * V_23 = V_21 -> V_24 [ V_37 ] ;
if ( ! V_23 )
continue;
if ( V_23 -> V_25 >= 0x10000 )
F_33 ( & V_2 -> V_2 ,
L_11 ,
V_37 ) ;
if ( V_23 -> div == 0 ) {
F_21 ( & V_2 -> V_2 , L_12 , V_37 ) ;
continue;
}
V_6 = F_18 ( & V_2 -> V_2 , V_21 -> V_24 [ V_37 ] ,
& V_4 -> V_28 [ V_37 ] , V_37 ) ;
if ( V_6 ) {
F_21 ( & V_2 -> V_2 ,
L_13 , V_37 ) ;
for ( V_37 -- ; V_37 >= 0 ; V_37 -- )
F_23 ( & V_2 -> V_2 ,
& V_4 -> V_28 [ V_37 ] ) ;
goto V_44;
}
}
return 0 ;
V_44:
F_34 ( V_4 -> V_42 ) ;
V_43:
F_12 ( & V_2 -> V_2 ) ;
V_41:
F_35 ( V_4 -> V_8 ) ;
return V_6 ;
}
static int F_36 ( struct V_36 * V_2 )
{
struct V_3 * V_4 = F_7 ( V_2 ) ;
int V_37 ;
F_12 ( & V_2 -> V_2 ) ;
for ( V_37 = 0 ; V_37 < F_32 ( V_4 -> V_28 ) ; V_37 ++ )
F_23 ( & V_2 -> V_2 , & V_4 -> V_28 [ V_37 ] ) ;
F_34 ( V_4 -> V_42 ) ;
F_35 ( V_4 -> V_8 ) ;
return 0 ;
}
