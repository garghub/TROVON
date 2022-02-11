static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 ;
F_2 ( L_1 , V_2 ) ;
V_4 = F_3 ( sizeof( * V_4 ) , V_5 ) ;
if ( ! V_4 )
return - V_6 ;
F_4 ( & V_4 -> V_7 ) ;
V_2 -> V_8 = V_4 ;
return 0 ;
}
static int F_5 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
F_2 ( L_1 , V_2 ) ;
F_6 ( & V_4 -> V_7 ) ;
F_7 ( V_4 -> V_9 ) ;
F_8 ( V_4 ) ;
V_2 -> V_8 = NULL ;
return 0 ;
}
static int F_9 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
F_2 ( L_1 , V_2 ) ;
F_6 ( & V_4 -> V_7 ) ;
return 0 ;
}
static struct V_10 * F_10 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
struct V_10 * V_11 ;
V_11 = F_11 ( & V_4 -> V_7 ) ;
if ( ! V_11 )
return V_11 ;
memcpy ( F_12 ( V_11 , 1 ) , & F_13 ( V_11 ) -> V_12 , 1 ) ;
return V_11 ;
}
static int F_14 ( struct V_1 * V_2 , struct V_10 * V_11 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
F_15 ( & V_4 -> V_7 , V_11 ) ;
return 0 ;
}
static int F_16 ( struct V_1 * V_2 , const void * V_13 , int V_14 )
{
struct V_3 * V_4 = V_2 -> V_8 ;
if ( ! F_17 ( V_15 , & V_2 -> V_16 ) )
return - V_17 ;
V_4 -> V_9 = F_18 ( V_2 -> V_18 , V_4 -> V_9 , V_13 , V_14 ,
V_19 ,
F_19 ( V_19 ) ) ;
if ( F_20 ( V_4 -> V_9 ) ) {
int V_20 = F_21 ( V_4 -> V_9 ) ;
F_22 ( V_2 -> V_18 , L_2 , V_20 ) ;
V_4 -> V_9 = NULL ;
return V_20 ;
}
return V_14 ;
}
static int F_23 ( struct V_21 * V_18 , T_1 V_22 , T_1 V_23 ,
const void * V_13 )
{
while ( V_23 > 0 ) {
struct V_10 * V_11 ;
T_2 V_24 [ 253 ] , V_25 = ( V_23 > 247 ) ? 247 : V_23 ;
T_3 V_26 = F_24 ( V_22 ) ;
memcpy ( V_24 , & V_26 , 4 ) ;
V_24 [ 4 ] = 0 ;
V_24 [ 5 ] = V_25 ;
memcpy ( V_24 + 6 , V_13 , V_25 ) ;
V_11 = F_25 ( V_18 , 0xfc8e , V_25 + 6 , V_24 ,
V_27 ) ;
if ( F_20 ( V_11 ) )
return F_21 ( V_11 ) ;
F_7 ( V_11 ) ;
V_23 -= V_25 ;
V_13 += V_25 ;
V_22 += V_25 ;
}
return 0 ;
}
static int F_26 ( struct V_1 * V_2 )
{
struct V_21 * V_18 = V_2 -> V_18 ;
struct V_10 * V_11 ;
struct V_28 V_29 ;
const struct V_30 * V_31 ;
const T_2 * V_32 ;
char V_33 [ 64 ] ;
bool V_34 = false ;
int V_20 ;
V_2 -> V_18 -> V_35 = V_36 ;
V_2 -> V_18 -> V_37 = V_38 ;
V_20 = F_27 ( V_18 ) ;
if ( V_20 )
return V_20 ;
V_20 = F_28 ( V_18 , & V_29 ) ;
if ( V_20 )
return V_20 ;
F_29 ( V_18 , & V_29 ) ;
if ( V_29 . V_39 != 0x37 ) {
F_22 ( V_18 , L_3 ,
V_29 . V_39 ) ;
return - V_40 ;
}
if ( V_29 . V_41 != 0x0a ) {
F_22 ( V_18 , L_4 ,
V_29 . V_41 ) ;
return - V_40 ;
}
snprintf ( V_33 , sizeof( V_33 ) , L_5 ,
V_29 . V_39 , V_29 . V_41 ) ;
V_20 = F_30 ( & V_31 , V_33 , & V_18 -> V_42 ) ;
if ( V_20 < 0 ) {
F_22 ( V_18 , L_6 ,
V_33 , V_20 ) ;
goto V_43;
}
V_32 = V_31 -> V_13 ;
F_31 ( V_18 , L_7 , V_33 ) ;
V_11 = F_32 ( V_18 , 0xfc2f , V_31 -> V_44 , V_31 -> V_13 ,
V_45 , V_46 ) ;
if ( F_20 ( V_11 ) ) {
F_22 ( V_18 , L_8 , F_21 ( V_11 ) ) ;
F_33 ( V_31 ) ;
return F_21 ( V_11 ) ;
}
F_7 ( V_11 ) ;
F_33 ( V_31 ) ;
V_43:
if ( V_29 . V_47 ) {
F_31 ( V_18 , L_9 ,
V_29 . V_47 ) ;
V_34 = true ;
goto V_48;
}
snprintf ( V_33 , sizeof( V_33 ) ,
L_10 ,
V_29 . V_39 , V_29 . V_41 , V_29 . V_49 ,
V_29 . V_50 , V_29 . V_51 , V_29 . V_52 ,
V_29 . V_53 , V_29 . V_54 ) ;
V_20 = F_30 ( & V_31 , V_33 , & V_18 -> V_42 ) ;
if ( V_20 < 0 ) {
F_22 ( V_18 , L_11 ,
V_33 , V_20 ) ;
goto V_48;
}
V_32 = V_31 -> V_13 ;
F_31 ( V_18 , L_12 , V_33 ) ;
while ( V_31 -> V_44 > V_32 - V_31 -> V_13 ) {
struct V_55 * V_56 = ( void * ) V_32 ;
T_1 V_22 , V_23 ;
if ( V_56 -> V_22 == 0xffffffff ) {
F_31 ( V_18 , L_13 ) ;
V_34 = true ;
break;
}
V_22 = F_34 ( V_56 -> V_22 ) ;
V_23 = F_34 ( V_56 -> V_23 ) ;
if ( V_31 -> V_13 + V_31 -> V_44 <= V_56 -> V_13 + V_23 ) {
F_31 ( V_18 , L_14 , V_23 ) ;
break;
}
F_31 ( V_18 , L_15 , ( V_32 - V_31 -> V_13 ) ,
V_31 -> V_44 ) ;
V_20 = F_23 ( V_18 , V_22 , V_23 , V_56 -> V_13 ) ;
if ( V_20 ) {
F_22 ( V_18 , L_16 ) ;
break;
}
V_32 = V_56 -> V_13 + V_23 ;
}
F_33 ( V_31 ) ;
V_48:
V_20 = F_35 ( V_18 , true , V_34 ) ;
if ( V_20 )
return V_20 ;
F_36 ( V_18 , false ) ;
F_37 ( V_18 ) ;
return 0 ;
}
int T_4 F_38 ( void )
{
return F_39 ( & V_57 ) ;
}
int T_5 F_40 ( void )
{
return F_41 ( & V_57 ) ;
}
