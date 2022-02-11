static int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
int V_5 ;
struct V_6 * V_7 = NULL ;
V_7 = F_2 ( sizeof( * V_7 ) , V_8 ) ;
if ( ! V_7 )
return - V_9 ;
V_7 -> type = V_10 ;
V_7 -> V_11 = F_3 ( V_2 -> V_12 [ V_13 ] ) ;
V_5 = F_4 ( V_7 , V_4 ) ;
if ( V_5 != 0 )
F_5 ( V_7 ) ;
return V_5 ;
}
static int F_6 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
int V_5 = - V_16 ;
struct V_3 V_4 ;
if ( ! V_2 -> V_12 [ V_13 ] ||
! V_2 -> V_12 [ V_17 ] )
return - V_16 ;
F_7 ( V_15 , & V_4 ) ;
switch ( F_3 ( V_2 -> V_12 [ V_17 ] ) ) {
case V_10 :
V_5 = F_1 ( V_2 , & V_4 ) ;
break;
}
if ( V_5 == 0 )
F_8 ( & V_18 ) ;
return V_5 ;
}
static int F_9 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
int V_5 ;
struct V_14 * V_19 = NULL ;
void * V_20 ;
T_1 V_11 ;
struct V_6 * V_7 ;
if ( ! V_2 -> V_12 [ V_13 ] ) {
V_5 = - V_16 ;
goto V_21;
}
V_11 = F_3 ( V_2 -> V_12 [ V_13 ] ) ;
V_7 = F_10 ( V_11 ) ;
if ( ! V_7 ) {
V_5 = - V_16 ;
goto V_21;
}
V_19 = F_11 ( V_22 , V_8 ) ;
if ( ! V_19 ) {
V_5 = - V_9 ;
goto V_23;
}
V_20 = F_12 ( V_19 , V_2 , & V_24 ,
0 , V_25 ) ;
if ( ! V_20 ) {
V_5 = - V_9 ;
goto V_23;
}
V_5 = F_13 ( V_19 , V_17 , V_7 -> type ) ;
if ( V_5 != 0 )
goto V_23;
F_14 ( V_7 ) ;
F_15 ( V_19 , V_20 ) ;
return F_16 ( V_19 , V_2 ) ;
V_23:
F_14 ( V_7 ) ;
V_21:
F_17 ( V_19 ) ;
return V_5 ;
}
static int F_18 ( struct V_6 * V_7 , void * V_26 )
{
int V_5 = - V_9 ;
struct V_27 * V_28 = V_26 ;
void * V_20 ;
V_20 = F_19 ( V_28 -> V_15 , F_20 ( V_28 -> V_29 -> V_15 ) . V_30 ,
V_28 -> V_31 , & V_24 ,
V_32 , V_33 ) ;
if ( ! V_20 )
goto V_34;
V_5 = F_13 ( V_28 -> V_15 , V_13 , V_7 -> V_11 ) ;
if ( V_5 != 0 )
goto V_34;
V_5 = F_13 ( V_28 -> V_15 ,
V_17 ,
V_7 -> type ) ;
if ( V_5 != 0 )
goto V_34;
F_15 ( V_28 -> V_15 , V_20 ) ;
return 0 ;
V_34:
F_21 ( V_28 -> V_15 , V_20 ) ;
return V_5 ;
}
static int F_22 ( struct V_14 * V_15 ,
struct V_35 * V_36 )
{
struct V_27 V_28 ;
T_1 V_37 = V_36 -> args [ 0 ] ;
V_28 . V_29 = V_36 ;
V_28 . V_15 = V_15 ;
V_28 . V_31 = V_36 -> V_38 -> V_39 ;
F_23 ( & V_37 , F_18 , & V_28 ) ;
V_36 -> args [ 0 ] = V_37 ;
return V_15 -> V_40 ;
}
static int F_24 ( struct V_41 * V_42 , void * V_26 )
{
struct V_43 * V_28 = V_26 ;
if ( V_42 -> V_44 . type == V_45 &&
V_42 -> V_44 . V_46 -> V_11 == V_28 -> V_11 )
return F_25 ( V_42 , V_28 -> V_4 ) ;
return 0 ;
}
static int F_26 ( struct V_14 * V_15 , struct V_1 * V_2 )
{
int V_5 = - V_16 ;
struct V_43 V_28 ;
struct V_3 V_4 ;
T_1 V_47 = 0 ;
T_1 V_48 = 0 ;
if ( ! V_2 -> V_12 [ V_13 ] )
return - V_16 ;
F_7 ( V_15 , & V_4 ) ;
V_28 . V_11 = F_3 ( V_2 -> V_12 [ V_13 ] ) ;
V_28 . V_4 = & V_4 ;
V_5 = F_27 ( & V_47 , & V_48 ,
F_24 , & V_28 ) ;
if ( V_5 == 0 || V_5 == - V_49 ) {
V_5 = F_28 ( V_28 . V_11 , & V_4 ) ;
if ( V_5 == 0 )
F_29 ( & V_18 ) ;
}
return V_5 ;
}
int T_2 F_30 ( void )
{
return F_31 ( & V_24 ) ;
}
const struct V_50 *
F_32 ( const struct V_50 * V_51 )
{
return F_33 ( & V_52 , V_51 ) ;
}
static const struct V_50 * F_34 ( void )
{
return F_35 ( V_52 ) ;
}
int F_4 ( struct V_6 * V_7 ,
struct V_3 * V_4 )
{
int V_5 = - V_53 ;
const struct V_50 * V_51 = F_34 () ;
if ( V_51 )
V_5 = V_51 -> V_54 ( V_7 , V_4 ) ;
return V_5 ;
}
void F_5 ( struct V_6 * V_7 )
{
const struct V_50 * V_51 = F_34 () ;
if ( V_51 )
V_51 -> V_55 ( V_7 ) ;
}
int F_28 ( T_1 V_11 , struct V_3 * V_4 )
{
int V_5 = - V_53 ;
const struct V_50 * V_51 = F_34 () ;
if ( V_51 )
V_5 = V_51 -> V_56 ( V_11 , V_4 ) ;
return V_5 ;
}
struct V_6 * F_10 ( T_1 V_11 )
{
struct V_6 * V_5 = NULL ;
const struct V_50 * V_51 = F_34 () ;
if ( V_51 )
V_5 = V_51 -> V_57 ( V_11 ) ;
return V_5 ;
}
void F_14 ( struct V_6 * V_7 )
{
const struct V_50 * V_51 = F_34 () ;
if ( V_51 )
V_51 -> V_58 ( V_7 ) ;
}
int F_23 ( T_1 * V_59 ,
int (* F_36)( struct V_6 * V_7 , void * V_26 ) ,
void * V_28 )
{
int V_5 = - V_53 ;
const struct V_50 * V_51 = F_34 () ;
if ( V_51 )
V_5 = V_51 -> V_60 ( V_59 , F_36 , V_28 ) ;
return V_5 ;
}
int F_37 ( struct V_61 * V_62 , struct V_63 * V_64 )
{
int V_5 = - V_53 ;
const struct V_50 * V_51 = F_34 () ;
if ( V_51 )
V_5 = V_51 -> V_65 ( V_62 , V_64 ) ;
return V_5 ;
}
int F_38 ( struct V_61 * V_62 ,
const struct V_6 * V_7 ,
const struct V_63 * V_64 )
{
int V_5 = - V_53 ;
const struct V_50 * V_51 = F_34 () ;
if ( V_51 )
V_5 = V_51 -> V_66 ( V_62 , V_7 , V_64 ) ;
return V_5 ;
}
void F_39 ( struct V_61 * V_62 )
{
const struct V_50 * V_51 = F_34 () ;
if ( V_51 )
V_51 -> V_67 ( V_62 ) ;
}
int F_40 ( struct V_68 * V_69 ,
const struct V_6 * V_7 ,
const struct V_63 * V_64 )
{
int V_5 = - V_53 ;
const struct V_50 * V_51 = F_34 () ;
if ( V_51 )
V_5 = V_51 -> V_70 ( V_69 , V_7 , V_64 ) ;
return V_5 ;
}
void F_41 ( struct V_68 * V_69 )
{
const struct V_50 * V_51 = F_34 () ;
if ( V_51 )
V_51 -> V_71 ( V_69 ) ;
}
unsigned char * F_42 ( const struct V_14 * V_15 )
{
unsigned char * V_5 = NULL ;
const struct V_50 * V_51 = F_34 () ;
if ( V_51 )
V_5 = V_51 -> V_72 ( V_15 ) ;
return V_5 ;
}
int F_43 ( const unsigned char * V_46 ,
struct V_63 * V_64 )
{
int V_5 = - V_53 ;
const struct V_50 * V_51 = F_34 () ;
if ( V_51 )
V_5 = V_51 -> V_73 ( V_46 , V_64 ) ;
return V_5 ;
}
int F_44 ( struct V_14 * V_15 ,
const struct V_6 * V_7 ,
const struct V_63 * V_64 )
{
int V_5 = - V_53 ;
const struct V_50 * V_51 = F_34 () ;
if ( V_51 )
V_5 = V_51 -> V_74 ( V_15 , V_7 , V_64 ) ;
return V_5 ;
}
int F_45 ( struct V_14 * V_15 )
{
int V_5 = - V_53 ;
const struct V_50 * V_51 = F_34 () ;
if ( V_51 )
V_5 = V_51 -> V_75 ( V_15 ) ;
return V_5 ;
}
void F_46 ( void )
{
const struct V_50 * V_51 = F_34 () ;
if ( V_51 )
V_51 -> V_76 () ;
}
int F_47 ( const unsigned char * V_77 ,
const struct V_63 * V_64 )
{
int V_5 = - V_53 ;
const struct V_50 * V_51 = F_34 () ;
if ( V_51 )
V_5 = V_51 -> V_78 ( V_77 , V_64 ) ;
return V_5 ;
}
