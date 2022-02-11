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
struct V_20 * V_21 = V_2 -> V_22 ;
struct V_23 * V_24 ;
int V_6 ;
V_24 = V_21 -> V_25 [ V_19 -> V_15 ] ;
V_6 = F_1 ( V_2 , V_4 , V_19 -> V_15 ) ;
if ( V_6 < 0 )
return V_6 ;
V_6 *= V_24 -> V_26 ;
V_6 = F_15 ( V_6 , V_24 -> div ) ;
return snprintf ( V_11 , V_16 , L_2 , V_6 ) ;
}
static T_1 F_16 ( struct V_1 * V_2 ,
struct V_9 * V_10 ,
char * V_11 )
{
struct V_13 * V_19 = F_9 ( V_10 ) ;
struct V_20 * V_21 = V_2 -> V_22 ;
struct V_23 * V_24 ;
V_24 = V_21 -> V_25 [ V_19 -> V_15 ] ;
return snprintf ( V_11 , V_16 , L_3 , V_24 -> V_27 ) ;
}
static int F_17 ( struct V_1 * V_2 ,
struct V_23 * V_24 ,
struct V_28 * V_29 ,
int V_5 )
{
struct V_13 * V_10 ;
int V_6 ;
snprintf ( V_29 -> V_30 , sizeof( V_29 -> V_30 ) , L_4 , V_5 ) ;
V_10 = & V_29 -> V_25 ;
V_10 -> V_15 = V_5 ;
F_18 ( & V_10 -> V_31 . V_10 ) ;
V_10 -> V_31 . V_10 . V_27 = V_29 -> V_30 ;
V_10 -> V_31 . V_10 . V_32 = V_33 ;
V_10 -> V_31 . V_34 = F_14 ;
V_6 = F_19 ( V_2 , & V_10 -> V_31 ) ;
if ( V_6 < 0 ) {
F_20 ( V_2 , L_5 ) ;
return V_6 ;
}
if ( V_24 -> V_27 ) {
snprintf ( V_29 -> V_35 , sizeof( V_29 -> V_35 ) ,
L_6 , V_5 ) ;
V_10 = & V_29 -> V_36 ;
V_10 -> V_15 = V_5 ;
F_18 ( & V_10 -> V_31 . V_10 ) ;
V_10 -> V_31 . V_10 . V_27 = V_29 -> V_35 ;
V_10 -> V_31 . V_10 . V_32 = V_33 ;
V_10 -> V_31 . V_34 = F_16 ;
V_6 = F_19 ( V_2 , & V_10 -> V_31 ) ;
if ( V_6 < 0 ) {
F_21 ( V_2 , & V_29 -> V_25 . V_31 ) ;
F_20 ( V_2 , L_7 ) ;
}
}
return V_6 ;
}
static void F_22 ( struct V_1 * V_2 ,
struct V_28 * V_29 )
{
F_21 ( V_2 , & V_29 -> V_25 . V_31 ) ;
F_21 ( V_2 , & V_29 -> V_36 . V_31 ) ;
}
static int F_23 ( struct V_37 * V_2 )
{
struct V_20 * V_21 = V_2 -> V_2 . V_22 ;
struct V_3 * V_4 ;
int V_6 = 0 ;
int V_38 ;
if ( ! V_21 ) {
F_20 ( & V_2 -> V_2 , L_8 ) ;
return - V_39 ;
}
V_4 = F_24 ( & V_2 -> V_2 , sizeof( struct V_3 ) , V_40 ) ;
if ( V_4 == NULL ) {
F_20 ( & V_2 -> V_2 , L_9 ) ;
return - V_41 ;
}
F_25 ( V_2 , V_4 ) ;
F_26 ( & V_4 -> V_7 ) ;
V_4 -> V_8 = F_27 ( V_2 , NULL , NULL , 0 ) ;
if ( F_28 ( V_4 -> V_8 ) ) {
F_20 ( & V_2 -> V_2 , L_10 ) ;
return F_29 ( V_4 -> V_8 ) ;
}
V_6 = F_10 ( & V_2 -> V_2 ) ;
if ( V_6 )
goto V_42;
V_4 -> V_43 = F_30 ( & V_2 -> V_2 ) ;
if ( F_28 ( V_4 -> V_43 ) ) {
F_20 ( & V_2 -> V_2 , L_11 ) ;
V_6 = F_29 ( V_4 -> V_43 ) ;
goto V_44;
}
for ( V_38 = 0 ; V_38 < F_31 ( V_21 -> V_25 ) ; V_38 ++ ) {
struct V_23 * V_24 = V_21 -> V_25 [ V_38 ] ;
if ( ! V_24 )
continue;
if ( V_24 -> V_26 >= 0x10000 )
F_32 ( & V_2 -> V_2 ,
L_12 ,
V_38 ) ;
if ( V_24 -> div == 0 ) {
F_20 ( & V_2 -> V_2 , L_13 , V_38 ) ;
continue;
}
V_6 = F_17 ( & V_2 -> V_2 , V_21 -> V_25 [ V_38 ] ,
& V_4 -> V_29 [ V_38 ] , V_38 ) ;
if ( V_6 ) {
F_20 ( & V_2 -> V_2 ,
L_14 , V_38 ) ;
for ( V_38 -- ; V_38 >= 0 ; V_38 -- )
F_22 ( & V_2 -> V_2 ,
& V_4 -> V_29 [ V_38 ] ) ;
goto V_45;
}
}
return 0 ;
V_45:
F_33 ( V_4 -> V_43 ) ;
V_44:
F_12 ( & V_2 -> V_2 ) ;
V_42:
F_34 ( V_4 -> V_8 ) ;
return V_6 ;
}
static int F_35 ( struct V_37 * V_2 )
{
struct V_3 * V_4 = F_7 ( V_2 ) ;
int V_38 ;
F_12 ( & V_2 -> V_2 ) ;
for ( V_38 = 0 ; V_38 < F_31 ( V_4 -> V_29 ) ; V_38 ++ )
F_22 ( & V_2 -> V_2 , & V_4 -> V_29 [ V_38 ] ) ;
F_33 ( V_4 -> V_43 ) ;
F_34 ( V_4 -> V_8 ) ;
return 0 ;
}
