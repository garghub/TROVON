static int F_1 ( struct V_1 * V_2 ,
const void * V_3 ,
T_1 V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
const struct V_7 * V_8 ;
const struct V_9 * V_10 ;
const struct V_11 * V_12 = V_3 ;
switch ( V_12 -> type ) {
case V_13 :
if ( V_4 != sizeof( * V_10 ) ) {
F_3 ( V_6 -> V_14 ,
L_1 ) ;
break;
}
V_10 = V_3 ;
F_4 ( V_6 -> V_14 , L_2 ,
V_10 -> V_15 , V_10 -> V_16 ,
V_10 -> V_10 , V_10 -> V_17 ) ;
F_5 ( & V_6 -> V_18 ) ;
break;
case V_19 :
if ( V_4 != sizeof( * V_8 ) ) {
F_3 ( V_6 -> V_14 ,
L_3 ) ;
break;
}
V_8 = V_3 ;
V_6 -> V_20 = V_8 -> V_21 ;
F_5 ( & V_6 -> V_18 ) ;
break;
case V_22 :
F_6 ( V_6 -> V_14 , L_4 ) ;
F_5 ( & V_6 -> V_23 ) ;
break;
default:
F_4 ( V_6 -> V_14 , L_5 , V_12 -> type ) ;
break;
}
return 0 ;
}
static int F_7 ( struct V_5 * V_6 )
{
struct V_11 V_24 ;
int V_25 ;
V_24 . type = V_26 ;
V_24 . V_27 = sizeof( V_24 ) ;
V_25 = F_8 ( V_6 -> V_2 , & V_24 , sizeof( V_24 ) ) ;
if ( V_25 < 0 )
return V_25 ;
V_25 = F_9 ( & V_6 -> V_18 , V_28 ) ;
if ( ! V_25 ) {
F_3 ( V_6 -> V_14 , L_6 ) ;
return - V_29 ;
}
return 0 ;
}
static int F_10 ( struct V_5 * V_6 , bool * V_30 )
{
struct V_31 * V_32 ;
const struct V_33 * V_34 ;
const void * V_3 ;
T_2 V_35 ;
int V_25 ;
V_32 = F_11 ( sizeof( * V_32 ) + V_36 , V_37 ) ;
if ( ! V_32 )
return - V_38 ;
V_25 = F_12 ( & V_34 , V_39 , V_6 -> V_14 ) ;
if ( V_25 < 0 ) {
F_3 ( V_6 -> V_14 , L_7 ,
V_39 , V_25 ) ;
goto V_40;
}
V_3 = V_34 -> V_3 ;
V_35 = V_34 -> V_41 ;
V_32 -> V_12 . type = V_42 ;
V_32 -> V_12 . V_27 = sizeof( * V_32 ) + V_36 ;
V_32 -> V_43 = 0 ;
V_32 -> V_44 = V_36 ;
V_32 -> V_45 = 0 ;
do {
if ( V_35 <= V_36 ) {
V_32 -> V_43 = 1 ;
V_32 -> V_44 = V_35 ;
V_32 -> V_12 . V_27 = sizeof( * V_32 ) + V_35 ;
}
memcpy ( V_32 -> V_46 , V_3 , V_32 -> V_44 ) ;
V_25 = F_8 ( V_6 -> V_2 , V_32 , V_32 -> V_12 . V_27 ) ;
if ( V_25 < 0 ) {
F_3 ( V_6 -> V_14 , L_8 ) ;
goto V_47;
}
V_32 -> V_45 ++ ;
V_3 += V_32 -> V_12 . V_27 ;
V_35 -= V_36 ;
} while ( V_35 > 0 );
V_25 = F_9 ( & V_6 -> V_18 , V_48 ) ;
if ( ! V_25 ) {
F_3 ( V_6 -> V_14 , L_9 ) ;
V_25 = - V_29 ;
} else {
* V_30 = V_6 -> V_20 == V_49 ;
V_25 = 0 ;
}
V_47:
F_13 ( V_34 ) ;
V_40:
F_14 ( V_32 ) ;
return V_25 ;
}
struct V_1 * F_15 ( void * V_6 , const char * V_50 , T_3 V_51 )
{
struct V_5 * V_52 = V_6 ;
return F_16 ( V_52 -> V_2 , V_50 , V_51 ) ;
}
static void F_17 ( struct V_53 * V_54 )
{
struct V_5 * V_6 = F_18 ( V_54 , struct V_5 , V_55 ) ;
bool V_30 ;
int V_25 ;
V_25 = F_7 ( V_6 ) ;
if ( V_25 < 0 )
return;
V_25 = F_10 ( V_6 , & V_30 ) ;
if ( V_25 < 0 )
return;
if ( V_30 ) {
V_25 = F_9 ( & V_6 -> V_23 , V_48 ) ;
if ( ! V_25 )
F_3 ( V_6 -> V_14 , L_10 ) ;
}
F_19 ( V_6 -> V_14 -> V_56 , NULL , NULL , V_6 -> V_14 ) ;
}
static int F_20 ( struct V_57 * V_58 )
{
struct V_5 * V_6 ;
V_6 = F_21 ( & V_58 -> V_14 , sizeof( * V_6 ) , V_37 ) ;
if ( ! V_6 )
return - V_38 ;
V_6 -> V_14 = & V_58 -> V_14 ;
V_6 -> V_2 = V_58 -> V_2 ;
F_22 ( & V_6 -> V_18 ) ;
F_22 ( & V_6 -> V_23 ) ;
F_23 ( & V_6 -> V_55 , F_17 ) ;
F_24 ( V_58 -> V_2 , V_6 ) ;
F_25 ( & V_58 -> V_14 , V_6 ) ;
F_26 ( & V_6 -> V_55 ) ;
return 0 ;
}
static void F_27 ( struct V_57 * V_58 )
{
struct V_5 * V_6 = F_2 ( V_58 -> V_2 ) ;
F_28 ( & V_6 -> V_55 ) ;
F_29 ( & V_58 -> V_14 ) ;
}
