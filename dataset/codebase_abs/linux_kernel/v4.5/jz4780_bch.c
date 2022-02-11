static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 , bool V_5 )
{
T_1 V_6 ;
F_2 ( F_3 ( V_2 -> V_7 + V_8 ) , V_2 -> V_7 + V_8 ) ;
V_6 = V_4 -> V_9 << V_10 ;
V_6 |= V_4 -> V_11 << V_12 ;
F_2 ( V_6 , V_2 -> V_7 + V_13 ) ;
V_6 = V_14 | V_15 ;
V_6 |= V_4 -> V_16 << V_17 ;
if ( V_5 )
V_6 |= V_18 ;
F_2 ( V_6 , V_2 -> V_7 + V_19 ) ;
}
static void F_4 ( struct V_1 * V_2 )
{
F_2 ( F_3 ( V_2 -> V_7 + V_8 ) , V_2 -> V_7 + V_8 ) ;
F_2 ( V_14 , V_2 -> V_7 + V_20 ) ;
}
static void F_5 ( struct V_1 * V_2 , const void * V_21 ,
T_2 V_9 )
{
T_2 V_22 = V_9 / sizeof( T_1 ) ;
T_2 V_23 = V_9 % sizeof( T_1 ) ;
const T_1 * V_24 ;
const T_3 * V_25 ;
V_24 = ( const T_1 * ) V_21 ;
while ( V_22 -- )
F_2 ( * V_24 ++ , V_2 -> V_7 + V_26 ) ;
V_25 = ( const T_3 * ) V_24 ;
while ( V_23 -- )
F_6 ( * V_25 ++ , V_2 -> V_7 + V_26 ) ;
}
static void F_7 ( struct V_1 * V_2 , void * V_21 ,
T_2 V_9 )
{
T_2 V_22 = V_9 / sizeof( T_1 ) ;
T_2 V_23 = V_9 % sizeof( T_1 ) ;
T_1 * V_27 ;
T_3 * V_28 ;
T_1 V_29 , V_30 = 0 ;
V_27 = ( T_1 * ) V_21 ;
while ( V_22 -- ) {
* V_27 ++ = F_3 ( V_2 -> V_7 + V_31 + V_30 ) ;
V_30 += sizeof( T_1 ) ;
}
V_28 = ( T_3 * ) V_27 ;
V_29 = F_3 ( V_2 -> V_7 + V_31 + V_30 ) ;
switch ( V_23 ) {
case 3 :
V_28 [ 2 ] = ( V_29 >> 16 ) & 0xff ;
case 2 :
V_28 [ 1 ] = ( V_29 >> 8 ) & 0xff ;
case 1 :
V_28 [ 0 ] = V_29 & 0xff ;
break;
}
}
static bool F_8 ( struct V_1 * V_2 , unsigned int V_32 ,
T_1 * V_33 )
{
T_1 V_6 ;
int V_34 ;
V_34 = F_9 ( V_2 -> V_7 + V_8 , V_6 ,
( V_6 & V_32 ) == V_32 , 0 , V_35 ) ;
if ( V_34 )
return false ;
if ( V_33 )
* V_33 = V_6 ;
F_2 ( V_6 , V_2 -> V_7 + V_8 ) ;
return true ;
}
int F_10 ( struct V_1 * V_2 , struct V_3 * V_4 ,
const T_3 * V_21 , T_3 * V_36 )
{
int V_34 = 0 ;
F_11 ( & V_2 -> V_37 ) ;
F_1 ( V_2 , V_4 , true ) ;
F_5 ( V_2 , V_21 , V_4 -> V_9 ) ;
if ( F_8 ( V_2 , V_38 , NULL ) ) {
F_7 ( V_2 , V_36 , V_4 -> V_11 ) ;
} else {
F_12 ( V_2 -> V_39 , L_1 ) ;
V_34 = - V_40 ;
}
F_4 ( V_2 ) ;
F_13 ( & V_2 -> V_37 ) ;
return V_34 ;
}
int F_14 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_3 * V_21 , T_3 * V_36 )
{
T_1 V_6 , V_41 , V_42 ;
int V_43 , V_34 , V_44 ;
F_11 ( & V_2 -> V_37 ) ;
F_1 ( V_2 , V_4 , false ) ;
F_5 ( V_2 , V_21 , V_4 -> V_9 ) ;
F_5 ( V_2 , V_36 , V_4 -> V_11 ) ;
if ( ! F_8 ( V_2 , V_45 , & V_6 ) ) {
F_12 ( V_2 -> V_39 , L_2 ) ;
V_34 = - V_40 ;
goto V_46;
}
if ( V_6 & V_47 ) {
F_15 ( V_2 -> V_39 , L_3 ) ;
V_34 = - V_48 ;
goto V_46;
}
if ( V_6 & V_49 ) {
V_44 = ( V_6 & V_50 ) >> V_51 ;
V_34 = ( V_6 & V_52 ) >> V_53 ;
for ( V_43 = 0 ; V_43 < V_44 ; V_43 ++ ) {
V_6 = F_3 ( V_2 -> V_7 + V_54 + ( V_43 * 4 ) ) ;
V_41 = ( V_6 & V_55 ) >>
V_56 ;
V_42 = ( V_6 & V_57 ) >>
V_58 ;
V_21 [ ( V_42 * 2 ) + 0 ] ^= V_41 ;
V_21 [ ( V_42 * 2 ) + 1 ] ^= V_41 >> 8 ;
}
} else {
V_34 = 0 ;
}
V_46:
F_4 ( V_2 ) ;
F_13 ( & V_2 -> V_37 ) ;
return V_34 ;
}
static struct V_1 * F_16 ( struct V_59 * V_60 )
{
struct V_61 * V_62 ;
struct V_1 * V_2 ;
V_62 = F_17 ( V_60 ) ;
if ( ! V_62 || ! F_18 ( V_62 ) )
return F_19 ( - V_63 ) ;
F_20 ( & V_62 -> V_39 ) ;
V_2 = F_18 ( V_62 ) ;
F_21 ( V_2 -> V_64 ) ;
V_2 -> V_39 = & V_62 -> V_39 ;
return V_2 ;
}
struct V_1 * F_22 ( struct V_59 * V_65 )
{
struct V_1 * V_2 = NULL ;
struct V_59 * V_60 ;
V_60 = F_23 ( V_65 , L_4 , 0 ) ;
if ( V_60 ) {
V_2 = F_16 ( V_60 ) ;
F_24 ( V_60 ) ;
}
return V_2 ;
}
void F_25 ( struct V_1 * V_2 )
{
F_26 ( V_2 -> V_64 ) ;
F_27 ( V_2 -> V_39 ) ;
}
static int F_28 ( struct V_61 * V_62 )
{
struct V_66 * V_39 = & V_62 -> V_39 ;
struct V_1 * V_2 ;
struct V_67 * V_68 ;
V_2 = F_29 ( V_39 , sizeof( * V_2 ) , V_69 ) ;
if ( ! V_2 )
return - V_70 ;
V_68 = F_30 ( V_62 , V_71 , 0 ) ;
V_2 -> V_7 = F_31 ( V_39 , V_68 ) ;
if ( F_32 ( V_2 -> V_7 ) )
return F_33 ( V_2 -> V_7 ) ;
F_4 ( V_2 ) ;
V_2 -> V_64 = F_34 ( V_39 , NULL ) ;
if ( F_32 ( V_2 -> V_64 ) ) {
F_12 ( V_39 , L_5 , F_33 ( V_2 -> V_64 ) ) ;
return F_33 ( V_2 -> V_64 ) ;
}
F_35 ( V_2 -> V_64 , V_72 ) ;
F_36 ( & V_2 -> V_37 ) ;
V_2 -> V_39 = V_39 ;
F_37 ( V_62 , V_2 ) ;
return 0 ;
}
