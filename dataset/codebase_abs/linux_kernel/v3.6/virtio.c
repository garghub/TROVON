static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_7 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 . V_1 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_7 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 . V_9 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_7 ) ;
return sprintf ( V_5 , L_2 , V_7 -> V_10 -> V_11 ( V_7 ) ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_7 ) ;
return sprintf ( V_5 , L_3 ,
V_7 -> V_8 . V_1 , V_7 -> V_8 . V_9 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_7 ) ;
unsigned int V_12 ;
T_1 V_13 = 0 ;
for ( V_12 = 0 ; V_12 < F_7 ( V_7 -> V_14 ) * V_15 ; V_12 ++ )
V_13 += sprintf ( V_5 + V_13 , L_4 ,
F_8 ( V_12 , V_7 -> V_14 ) ? '1' : '0' ) ;
V_13 += sprintf ( V_5 + V_13 , L_5 ) ;
return V_13 ;
}
static inline int F_9 ( const struct V_6 * V_7 ,
const struct V_16 * V_8 )
{
if ( V_8 -> V_1 != V_7 -> V_8 . V_1 && V_8 -> V_1 != V_17 )
return 0 ;
return V_8 -> V_9 == V_17 || V_8 -> V_9 == V_7 -> V_8 . V_9 ;
}
static int F_10 ( struct V_1 * V_18 , struct V_19 * V_20 )
{
unsigned int V_12 ;
struct V_6 * V_7 = F_2 ( V_18 , struct V_6 , V_7 ) ;
const struct V_16 * V_21 ;
V_21 = F_2 ( V_20 , struct V_22 , V_23 ) -> V_24 ;
for ( V_12 = 0 ; V_21 [ V_12 ] . V_1 ; V_12 ++ )
if ( F_9 ( V_7 , & V_21 [ V_12 ] ) )
return 1 ;
return 0 ;
}
static int F_11 ( struct V_1 * V_18 , struct V_25 * V_26 )
{
struct V_6 * V_7 = F_2 ( V_18 , struct V_6 , V_7 ) ;
return F_12 ( V_26 , L_6 ,
V_7 -> V_8 . V_1 , V_7 -> V_8 . V_9 ) ;
}
static void F_13 ( struct V_6 * V_7 , unsigned V_27 )
{
V_7 -> V_10 -> V_28 ( V_7 , V_7 -> V_10 -> V_11 ( V_7 ) | V_27 ) ;
}
void F_14 ( const struct V_6 * V_29 ,
unsigned int V_30 )
{
unsigned int V_12 ;
struct V_22 * V_31 = F_2 ( V_29 -> V_7 . V_23 ,
struct V_22 , V_23 ) ;
for ( V_12 = 0 ; V_12 < V_31 -> V_32 ; V_12 ++ )
if ( V_31 -> V_33 [ V_12 ] == V_30 )
return;
F_15 () ;
}
static int F_16 ( struct V_1 * V_2 )
{
int V_34 , V_12 ;
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_7 ) ;
struct V_22 * V_31 = F_2 ( V_7 -> V_7 . V_23 ,
struct V_22 , V_23 ) ;
T_2 V_35 ;
F_13 ( V_7 , V_36 ) ;
V_35 = V_7 -> V_10 -> V_37 ( V_7 ) ;
memset ( V_7 -> V_14 , 0 , sizeof( V_7 -> V_14 ) ) ;
for ( V_12 = 0 ; V_12 < V_31 -> V_32 ; V_12 ++ ) {
unsigned int V_38 = V_31 -> V_33 [ V_12 ] ;
F_17 ( V_38 >= 32 ) ;
if ( V_35 & ( 1 << V_38 ) )
F_18 ( V_38 , V_7 -> V_14 ) ;
}
for ( V_12 = V_39 ; V_12 < V_40 ; V_12 ++ )
if ( V_35 & ( 1 << V_12 ) )
F_18 ( V_12 , V_7 -> V_14 ) ;
V_7 -> V_10 -> V_41 ( V_7 ) ;
V_34 = V_31 -> V_42 ( V_7 ) ;
if ( V_34 )
F_13 ( V_7 , V_43 ) ;
else {
F_13 ( V_7 , V_44 ) ;
if ( V_31 -> V_45 )
V_31 -> V_45 ( V_7 ) ;
}
return V_34 ;
}
static int F_19 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 , struct V_6 , V_7 ) ;
struct V_22 * V_31 = F_2 ( V_7 -> V_7 . V_23 ,
struct V_22 , V_23 ) ;
V_31 -> remove ( V_7 ) ;
F_17 ( V_7 -> V_10 -> V_11 ( V_7 ) ) ;
F_13 ( V_7 , V_46 ) ;
return 0 ;
}
int F_20 ( struct V_22 * V_23 )
{
F_17 ( V_23 -> V_32 && ! V_23 -> V_33 ) ;
V_23 -> V_23 . V_47 = & V_48 ;
return F_21 ( & V_23 -> V_23 ) ;
}
void F_22 ( struct V_22 * V_23 )
{
F_23 ( & V_23 -> V_23 ) ;
}
int F_24 ( struct V_6 * V_7 )
{
int V_34 ;
V_7 -> V_7 . V_47 = & V_48 ;
V_34 = F_25 ( & V_49 , 0 , 0 , V_50 ) ;
if ( V_34 < 0 )
goto V_51;
V_7 -> V_52 = V_34 ;
F_26 ( & V_7 -> V_7 , L_7 , V_7 -> V_52 ) ;
V_7 -> V_10 -> V_53 ( V_7 ) ;
F_13 ( V_7 , V_46 ) ;
F_27 ( & V_7 -> V_54 ) ;
V_34 = F_28 ( & V_7 -> V_7 ) ;
V_51:
if ( V_34 )
F_13 ( V_7 , V_43 ) ;
return V_34 ;
}
void F_29 ( struct V_6 * V_7 )
{
F_30 ( & V_7 -> V_7 ) ;
F_31 ( & V_49 , V_7 -> V_52 ) ;
}
static int F_32 ( void )
{
if ( F_33 ( & V_48 ) != 0 )
F_34 ( L_8 ) ;
return 0 ;
}
static void T_3 F_35 ( void )
{
F_36 ( & V_48 ) ;
}
