static T_1 F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 . V_1 ) ;
}
static T_1 F_3 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_1 , V_7 -> V_8 . V_9 ) ;
}
static T_1 F_4 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_2 , V_7 -> V_10 -> V_11 ( V_7 ) ) ;
}
static T_1 F_5 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
return sprintf ( V_5 , L_3 ,
V_7 -> V_8 . V_1 , V_7 -> V_8 . V_9 ) ;
}
static T_1 F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 , char * V_5 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
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
struct V_6 * V_7 = F_2 ( V_18 ) ;
const struct V_16 * V_21 ;
V_21 = F_11 ( V_20 ) -> V_22 ;
for ( V_12 = 0 ; V_21 [ V_12 ] . V_1 ; V_12 ++ )
if ( F_9 ( V_7 , & V_21 [ V_12 ] ) )
return 1 ;
return 0 ;
}
static int F_12 ( struct V_1 * V_18 , struct V_23 * V_24 )
{
struct V_6 * V_7 = F_2 ( V_18 ) ;
return F_13 ( V_24 , L_6 ,
V_7 -> V_8 . V_1 , V_7 -> V_8 . V_9 ) ;
}
static void F_14 ( struct V_6 * V_7 , unsigned V_25 )
{
V_7 -> V_10 -> V_26 ( V_7 , V_7 -> V_10 -> V_11 ( V_7 ) | V_25 ) ;
}
void F_15 ( const struct V_6 * V_27 ,
unsigned int V_28 )
{
unsigned int V_12 ;
struct V_29 * V_30 = F_11 ( V_27 -> V_7 . V_31 ) ;
for ( V_12 = 0 ; V_12 < V_30 -> V_32 ; V_12 ++ )
if ( V_30 -> V_33 [ V_12 ] == V_28 )
return;
F_16 () ;
}
static void F_17 ( struct V_6 * V_7 )
{
struct V_29 * V_30 = F_11 ( V_7 -> V_7 . V_31 ) ;
if ( ! V_7 -> V_34 )
V_7 -> V_35 = true ;
else if ( V_30 && V_30 -> V_36 )
V_30 -> V_36 ( V_7 ) ;
}
void F_18 ( struct V_6 * V_7 )
{
unsigned long V_37 ;
F_19 ( & V_7 -> V_38 , V_37 ) ;
F_17 ( V_7 ) ;
F_20 ( & V_7 -> V_38 , V_37 ) ;
}
static void F_21 ( struct V_6 * V_7 )
{
F_22 ( & V_7 -> V_38 ) ;
V_7 -> V_34 = false ;
F_23 ( & V_7 -> V_38 ) ;
}
static void F_24 ( struct V_6 * V_7 )
{
F_22 ( & V_7 -> V_38 ) ;
V_7 -> V_34 = true ;
if ( V_7 -> V_35 )
F_17 ( V_7 ) ;
V_7 -> V_35 = false ;
F_23 ( & V_7 -> V_38 ) ;
}
static int F_25 ( struct V_1 * V_2 )
{
int V_39 , V_12 ;
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_11 ( V_7 -> V_7 . V_31 ) ;
T_2 V_40 ;
F_14 ( V_7 , V_41 ) ;
V_40 = V_7 -> V_10 -> V_42 ( V_7 ) ;
memset ( V_7 -> V_14 , 0 , sizeof( V_7 -> V_14 ) ) ;
for ( V_12 = 0 ; V_12 < V_30 -> V_32 ; V_12 ++ ) {
unsigned int V_43 = V_30 -> V_33 [ V_12 ] ;
F_26 ( V_43 >= 32 ) ;
if ( V_40 & ( 1 << V_43 ) )
F_27 ( V_43 , V_7 -> V_14 ) ;
}
for ( V_12 = V_44 ; V_12 < V_45 ; V_12 ++ )
if ( V_40 & ( 1 << V_12 ) )
F_27 ( V_12 , V_7 -> V_14 ) ;
V_7 -> V_10 -> V_46 ( V_7 ) ;
V_39 = V_30 -> V_47 ( V_7 ) ;
if ( V_39 )
F_14 ( V_7 , V_48 ) ;
else {
F_14 ( V_7 , V_49 ) ;
if ( V_30 -> V_50 )
V_30 -> V_50 ( V_7 ) ;
F_24 ( V_7 ) ;
}
return V_39 ;
}
static int F_28 ( struct V_1 * V_2 )
{
struct V_6 * V_7 = F_2 ( V_2 ) ;
struct V_29 * V_30 = F_11 ( V_7 -> V_7 . V_31 ) ;
F_21 ( V_7 ) ;
V_30 -> remove ( V_7 ) ;
F_29 ( V_7 -> V_10 -> V_11 ( V_7 ) ) ;
F_14 ( V_7 , V_51 ) ;
return 0 ;
}
int F_30 ( struct V_29 * V_31 )
{
F_26 ( V_31 -> V_32 && ! V_31 -> V_33 ) ;
V_31 -> V_31 . V_52 = & V_53 ;
return F_31 ( & V_31 -> V_31 ) ;
}
void F_32 ( struct V_29 * V_31 )
{
F_33 ( & V_31 -> V_31 ) ;
}
int F_34 ( struct V_6 * V_7 )
{
int V_39 ;
V_7 -> V_7 . V_52 = & V_53 ;
V_39 = F_35 ( & V_54 , 0 , 0 , V_55 ) ;
if ( V_39 < 0 )
goto V_56;
V_7 -> V_57 = V_39 ;
F_36 ( & V_7 -> V_7 , L_7 , V_7 -> V_57 ) ;
F_37 ( & V_7 -> V_38 ) ;
V_7 -> V_34 = false ;
V_7 -> V_35 = false ;
V_7 -> V_10 -> V_58 ( V_7 ) ;
F_14 ( V_7 , V_51 ) ;
F_38 ( & V_7 -> V_59 ) ;
V_39 = F_39 ( & V_7 -> V_7 ) ;
V_56:
if ( V_39 )
F_14 ( V_7 , V_48 ) ;
return V_39 ;
}
void F_40 ( struct V_6 * V_7 )
{
int V_57 = V_7 -> V_57 ;
F_41 ( & V_7 -> V_7 ) ;
F_42 ( & V_54 , V_57 ) ;
}
int F_43 ( struct V_6 * V_7 )
{
struct V_29 * V_30 = F_11 ( V_7 -> V_7 . V_31 ) ;
F_21 ( V_7 ) ;
V_7 -> V_60 = V_7 -> V_10 -> V_11 ( V_7 ) & V_48 ;
if ( V_30 && V_30 -> V_61 )
return V_30 -> V_61 ( V_7 ) ;
return 0 ;
}
int F_44 ( struct V_6 * V_7 )
{
struct V_29 * V_30 = F_11 ( V_7 -> V_7 . V_31 ) ;
V_7 -> V_10 -> V_58 ( V_7 ) ;
F_14 ( V_7 , V_51 ) ;
if ( V_7 -> V_60 )
F_14 ( V_7 , V_48 ) ;
if ( ! V_30 )
return 0 ;
F_14 ( V_7 , V_41 ) ;
V_7 -> V_10 -> V_46 ( V_7 ) ;
if ( V_30 -> V_62 ) {
int V_63 = V_30 -> V_62 ( V_7 ) ;
if ( V_63 ) {
F_14 ( V_7 , V_48 ) ;
return V_63 ;
}
}
F_14 ( V_7 , V_49 ) ;
F_24 ( V_7 ) ;
return 0 ;
}
static int F_45 ( void )
{
if ( F_46 ( & V_53 ) != 0 )
F_47 ( L_8 ) ;
return 0 ;
}
static void T_3 F_48 ( void )
{
F_49 ( & V_53 ) ;
}
