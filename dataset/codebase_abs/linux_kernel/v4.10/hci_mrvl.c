static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( L_1 , V_2 ) ;
V_4 = F_3 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return - V_6 ;
F_4 ( & V_4 -> V_7 ) ;
F_4 ( & V_4 -> V_8 ) ;
F_5 ( V_9 , & V_4 -> V_10 ) ;
V_2 -> V_11 = V_4 ;
return 0 ;
}
static int F_6 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_11 ;
F_2 ( L_1 , V_2 ) ;
F_7 ( & V_4 -> V_7 ) ;
F_7 ( & V_4 -> V_8 ) ;
F_8 ( V_4 -> V_12 ) ;
F_9 ( V_4 ) ;
V_2 -> V_11 = NULL ;
return 0 ;
}
static int F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_11 ;
F_2 ( L_1 , V_2 ) ;
F_7 ( & V_4 -> V_7 ) ;
F_7 ( & V_4 -> V_8 ) ;
return 0 ;
}
static struct V_13 * F_11 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_11 ;
struct V_13 * V_14 ;
V_14 = F_12 ( & V_4 -> V_7 ) ;
if ( ! V_14 ) {
V_14 = F_12 ( & V_4 -> V_8 ) ;
} else {
memcpy ( F_13 ( V_14 , 1 ) , & F_14 ( V_14 ) -> V_15 , 1 ) ;
}
return V_14 ;
}
static int F_15 ( struct V_1 * V_2 , struct V_13 * V_14 )
{
struct V_3 * V_4 = V_2 -> V_11 ;
F_16 ( & V_4 -> V_7 , V_14 ) ;
return 0 ;
}
static void F_17 ( struct V_1 * V_2 , unsigned char type )
{
struct V_3 * V_4 = V_2 -> V_11 ;
struct V_13 * V_14 ;
V_14 = F_18 ( 0 , V_16 ) ;
if ( ! V_14 ) {
F_19 ( V_2 -> V_17 , L_2 ) ;
return;
}
F_20 ( V_14 ) = type ;
F_16 ( & V_4 -> V_7 , V_14 ) ;
F_21 ( V_2 ) ;
}
static int F_22 ( struct V_18 * V_17 , struct V_13 * V_14 )
{
struct V_19 * V_20 = ( void * ) V_14 -> V_21 ;
struct V_1 * V_2 = F_23 ( V_17 ) ;
struct V_3 * V_4 = V_2 -> V_11 ;
int V_22 = 0 ;
if ( ( V_20 -> V_23 ^ V_20 -> V_24 ) != 0xffff ) {
F_19 ( V_17 , L_3 ) ;
F_17 ( V_2 , V_25 ) ;
V_22 = - V_26 ;
goto V_27;
}
F_17 ( V_2 , V_28 ) ;
if ( ! F_24 ( V_29 , & V_4 -> V_10 ) ) {
F_19 ( V_17 , L_4 ) ;
V_22 = - V_26 ;
goto V_27;
}
V_4 -> V_30 = F_25 ( V_20 -> V_23 ) ;
F_26 ( V_29 , & V_4 -> V_10 ) ;
F_27 () ;
F_28 ( & V_4 -> V_10 , V_29 ) ;
V_27:
F_8 ( V_14 ) ;
return V_22 ;
}
static int F_29 ( struct V_18 * V_17 , struct V_13 * V_14 )
{
struct V_19 * V_20 = ( void * ) V_14 -> V_21 ;
struct V_1 * V_2 = F_23 ( V_17 ) ;
struct V_3 * V_4 = V_2 -> V_11 ;
T_1 V_31 = F_25 ( V_20 -> V_23 ) ;
int V_22 = 0 ;
if ( ( V_20 -> V_23 ^ V_20 -> V_24 ) != 0xffff ) {
F_19 ( V_17 , L_3 ) ;
F_17 ( V_2 , V_25 ) ;
V_22 = - V_26 ;
goto V_27;
}
F_17 ( V_2 , V_28 ) ;
if ( ! F_24 ( V_9 , & V_4 -> V_10 ) ) {
F_19 ( V_17 , L_5 ) ;
goto V_27;
}
V_4 -> V_32 = V_31 ;
V_4 -> V_33 = V_31 >> 8 ;
F_30 ( V_17 , L_6 , V_4 -> V_32 , V_4 -> V_33 ) ;
F_26 ( V_9 , & V_4 -> V_10 ) ;
F_27 () ;
F_28 ( & V_4 -> V_10 , V_9 ) ;
V_27:
F_8 ( V_14 ) ;
return V_22 ;
}
static int F_31 ( struct V_1 * V_2 , const void * V_21 , int V_34 )
{
struct V_3 * V_4 = V_2 -> V_11 ;
if ( ! F_24 ( V_35 , & V_2 -> V_10 ) )
return - V_36 ;
V_4 -> V_12 = F_32 ( V_2 -> V_17 , V_4 -> V_12 , V_21 , V_34 ,
V_37 ,
F_33 ( V_37 ) ) ;
if ( F_34 ( V_4 -> V_12 ) ) {
int V_38 = F_35 ( V_4 -> V_12 ) ;
F_19 ( V_2 -> V_17 , L_7 , V_38 ) ;
V_4 -> V_12 = NULL ;
return V_38 ;
}
return V_34 ;
}
static int F_36 ( struct V_18 * V_17 , const char * V_39 )
{
struct V_1 * V_2 = F_23 ( V_17 ) ;
struct V_3 * V_4 = V_2 -> V_11 ;
const struct V_40 * V_41 = NULL ;
const T_2 * V_42 , * V_43 ;
int V_38 ;
V_38 = F_37 ( & V_41 , V_39 , & V_17 -> V_44 ) ;
if ( V_38 < 0 ) {
F_19 ( V_17 , L_8 , V_39 ) ;
return V_38 ;
}
V_42 = V_41 -> V_21 ;
V_43 = V_41 -> V_21 + V_41 -> V_45 ;
F_30 ( V_17 , L_9 , V_39 ) ;
F_5 ( V_29 , & V_4 -> V_10 ) ;
while ( V_42 <= V_43 ) {
struct V_13 * V_14 ;
V_38 = F_38 ( & V_4 -> V_10 , V_29 ,
V_46 ,
F_39 ( 2000 ) ) ;
if ( V_38 == 1 ) {
F_19 ( V_17 , L_10 ) ;
V_38 = - V_47 ;
break;
} else if ( V_38 ) {
F_19 ( V_17 , L_11 ) ;
V_38 = - V_48 ;
break;
}
F_40 ( V_17 , L_12 ,
V_4 -> V_30 ) ;
if ( V_42 == V_43 ) {
if ( ! V_4 -> V_30 ) {
F_30 ( V_17 , L_13 ) ;
} else {
F_19 ( V_17 , L_14 ) ;
V_38 = - V_26 ;
}
break;
}
if ( V_42 + V_4 -> V_30 > V_43 ) {
V_4 -> V_30 = V_43 - V_42 ;
F_40 ( V_17 , L_15 ,
V_4 -> V_30 ) ;
}
V_14 = F_18 ( V_4 -> V_30 , V_5 ) ;
if ( ! V_14 ) {
F_19 ( V_17 , L_16 ) ;
V_38 = - V_6 ;
break;
}
F_14 ( V_14 ) -> V_15 = V_49 ;
memcpy ( F_41 ( V_14 , V_4 -> V_30 ) , V_42 , V_4 -> V_30 ) ;
V_42 += V_4 -> V_30 ;
F_5 ( V_29 , & V_4 -> V_10 ) ;
F_16 ( & V_4 -> V_8 , V_14 ) ;
F_21 ( V_2 ) ;
}
F_42 ( V_41 ) ;
return V_38 ;
}
static int F_43 ( struct V_1 * V_2 )
{
int V_38 ;
F_44 ( V_2 , true ) ;
V_38 = F_36 ( V_2 -> V_17 , L_17 ) ;
if ( V_38 ) {
F_19 ( V_2 -> V_17 , L_18 ) ;
return - V_26 ;
}
F_45 ( V_2 , 3000000 ) ;
F_44 ( V_2 , false ) ;
V_38 = F_36 ( V_2 -> V_17 , L_19 ) ;
if ( V_38 )
return V_38 ;
return 0 ;
}
int T_3 F_46 ( void )
{
return F_47 ( & V_50 ) ;
}
int T_4 F_48 ( void )
{
return F_49 ( & V_50 ) ;
}
