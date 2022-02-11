static int F_1 ( struct V_1 * V_2 , int V_3 )
{
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
int V_7 = 0 ;
F_2 ( & V_2 -> V_8 -> V_2 , L_1 , V_9 , F_3 ( & V_5 -> V_10 ) , V_3 ) ;
if ( ( V_3 && F_4 ( 1 , & V_5 -> V_10 ) == 1 ) || ( ! V_3 && F_5 ( & V_5 -> V_10 ) ) ) {
V_7 = F_6 ( V_2 -> V_8 ) ;
if ( V_7 < 0 )
goto V_11;
V_2 -> V_8 -> V_12 = V_3 ;
F_7 ( V_2 -> V_8 ) ;
}
V_11:
return V_7 ;
}
static int F_8 ( struct V_13 * V_8 , int V_3 )
{
struct V_1 * V_2 = F_9 ( V_8 ) ;
if ( ! V_2 )
return 0 ;
return F_1 ( V_2 , V_3 ) ;
}
static int F_10 ( struct V_1 * V_2 )
{
int V_7 ;
struct V_14 * V_15 = NULL ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
V_7 = F_11 ( V_2 , V_5 -> V_6 ) ;
if ( V_7 < 0 )
goto V_11;
if ( V_5 -> V_16 != V_5 -> V_6 )
V_2 -> V_17 = & V_5 -> V_16 -> V_18 -> V_19 [ 0 ] ;
if ( ! V_2 -> V_17 ) {
V_7 = - V_20 ;
goto V_11;
}
F_12 ( & V_5 -> V_10 , 0 ) ;
V_15 = F_13 ( V_5 -> V_16 , & V_2 -> V_17 -> V_21 , 4096 , & F_8 ) ;
if ( F_14 ( V_15 ) ) {
F_15 ( & V_5 -> V_16 -> V_2 , L_2 ) ;
V_7 = F_16 ( V_15 ) ;
goto V_11;
}
V_2 -> V_17 = NULL ;
V_5 -> V_15 = V_15 ;
V_11:
return V_7 ;
}
static int F_17 ( struct V_1 * V_2 , struct V_13 * V_8 )
{
int V_17 = - 1 ;
T_1 * V_22 = V_8 -> V_18 -> V_23 ;
int V_24 = V_8 -> V_18 -> V_25 ;
struct V_26 * V_21 = & V_8 -> V_18 -> V_21 ;
struct V_27 * V_28 = NULL ;
struct V_29 * V_30 = NULL ;
T_2 V_31 = 0 ;
struct V_14 * V_32 = F_18 ( V_8 ) ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
F_19 ( ( sizeof( ( (struct V_1 * ) 0 ) -> V_6 ) < sizeof( struct V_4 ) ) ) ;
if ( V_8 -> V_18 -> V_21 . V_33 == 3 ) {
V_5 -> V_16 = V_8 ;
V_5 -> V_6 = V_8 ;
goto V_34;
}
if ( V_8 -> V_18 -> V_21 . V_33 != 1 )
goto V_11;
while ( V_24 > 3 ) {
struct V_35 * V_36 = ( void * ) V_22 ;
if ( V_36 -> V_37 != V_38 )
goto V_39;
switch ( V_22 [ 2 ] ) {
case V_40 :
if ( V_31 & 1 << V_40 ) {
F_2 ( & V_8 -> V_2 , L_3 ) ;
goto V_11;
}
if ( V_36 -> V_41 != sizeof( struct V_42 ) ) {
F_2 ( & V_8 -> V_2 , L_4 , V_36 -> V_41 ) ;
goto V_11;
}
break;
case V_43 :
if ( V_31 & 1 << V_43 ) {
F_2 ( & V_8 -> V_2 , L_5 ) ;
goto V_11;
}
if ( V_36 -> V_41 != sizeof( struct V_27 ) ) {
F_2 ( & V_8 -> V_2 , L_6 , V_36 -> V_41 ) ;
goto V_11;
}
V_28 = (struct V_27 * ) V_22 ;
break;
case V_44 :
if ( V_31 & 1 << V_44 ) {
F_2 ( & V_8 -> V_2 , L_7 ) ;
goto V_11;
}
if ( V_36 -> V_41 != sizeof( struct V_29 ) ) {
F_2 ( & V_8 -> V_2 , L_8 , V_36 -> V_41 ) ;
goto V_11;
}
V_30 = (struct V_29 * ) V_22 ;
break;
}
if ( V_22 [ 2 ] < 32 )
V_31 |= 1 << V_22 [ 2 ] ;
V_39:
V_24 -= V_36 -> V_41 ;
V_22 += V_36 -> V_41 ;
}
if ( ! ( V_31 & ( 1 << V_40 ) ) ||
! ( V_31 & ( 1 << V_43 ) ) ) {
F_15 ( & V_8 -> V_2 , L_9 ) ;
goto V_11;
}
if ( V_21 -> V_45 != V_28 -> V_46 ) {
F_15 ( & V_8 -> V_2 , L_10 , V_28 -> V_46 ) ;
goto V_11;
}
V_5 -> V_16 = V_8 ;
V_5 -> V_6 = F_20 ( V_2 -> V_47 , V_28 -> V_48 ) ;
if ( ! V_5 -> V_6 ) {
F_15 ( & V_8 -> V_2 , L_11 , V_28 -> V_48 ) ;
goto V_11;
}
if ( V_30 ) {
V_2 -> V_49 = F_21 ( V_30 -> V_50 ) ;
F_22 ( V_2 , V_30 -> V_51 ) ;
}
V_17 = F_23 ( V_32 , V_5 -> V_6 , V_2 ) ;
if ( V_17 < 0 )
goto V_11;
V_34:
V_17 = F_10 ( V_2 ) ;
if ( V_17 < 0 && V_5 -> V_16 != V_5 -> V_6 ) {
F_24 ( V_5 -> V_6 , NULL ) ;
F_25 ( V_32 , V_5 -> V_6 ) ;
}
V_11:
return V_17 ;
}
static void F_26 ( struct V_1 * V_2 , struct V_13 * V_8 )
{
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
struct V_14 * V_32 = F_18 ( V_8 ) ;
struct V_13 * V_52 ;
if ( V_5 -> V_15 && V_5 -> V_15 -> V_53 )
V_5 -> V_15 -> V_53 ( V_5 -> V_16 ) ;
if ( V_8 == V_5 -> V_16 )
V_52 = V_5 -> V_6 ;
else
V_52 = V_5 -> V_16 ;
if ( V_52 && V_8 != V_52 ) {
F_24 ( V_52 , NULL ) ;
F_25 ( V_32 , V_52 ) ;
}
V_5 -> V_15 = NULL ;
V_5 -> V_6 = NULL ;
V_5 -> V_16 = NULL ;
}
static int F_27 ( struct V_13 * V_8 , T_3 V_54 )
{
struct V_1 * V_2 = F_9 ( V_8 ) ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
int V_55 ;
V_55 = F_28 ( V_8 , V_54 ) ;
if ( V_55 < 0 )
goto V_11;
if ( V_8 == V_5 -> V_16 && V_5 -> V_15 && V_5 -> V_15 -> V_56 )
V_55 = V_5 -> V_15 -> V_56 ( V_8 , V_54 ) ;
if ( V_55 < 0 )
F_29 ( V_8 ) ;
V_11:
return V_55 ;
}
static int F_30 ( struct V_13 * V_8 )
{
struct V_1 * V_2 = F_9 ( V_8 ) ;
struct V_4 * V_5 = ( void * ) & V_2 -> V_6 ;
int V_55 = 0 ;
bool V_57 = ( V_8 == V_5 -> V_16 && V_5 -> V_15 && V_5 -> V_15 -> V_58 ) ;
if ( V_57 )
V_55 = V_5 -> V_15 -> V_58 ( V_8 ) ;
if ( V_55 < 0 )
goto V_11;
V_55 = F_29 ( V_8 ) ;
if ( V_55 < 0 && V_57 && V_5 -> V_15 -> V_56 )
V_5 -> V_15 -> V_56 ( V_8 , V_59 ) ;
V_11:
return V_55 ;
}
static int F_31 ( struct V_13 * V_8 , const struct V_60 * V_61 )
{
struct V_60 * V_62 = (struct V_60 * ) V_61 ;
if ( ! V_62 -> V_63 ) {
F_2 ( & V_8 -> V_2 , L_12 ) ;
V_62 -> V_63 = ( unsigned long ) & V_64 ;
}
return F_32 ( V_8 , V_62 ) ;
}
