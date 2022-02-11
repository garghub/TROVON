static int F_1 ( struct V_1 * V_2 ,
void * V_3 ,
int V_4 ,
void * V_5 ,
T_1 V_6 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
const struct V_10 * V_11 ;
const struct V_12 * V_13 ;
const struct V_14 * V_15 = V_3 ;
switch ( V_15 -> type ) {
case V_16 :
if ( V_4 != sizeof( * V_13 ) ) {
F_3 ( V_8 -> V_9 ,
L_1 ) ;
break;
}
V_13 = V_3 ;
F_4 ( V_8 -> V_9 , L_2 ,
V_13 -> V_17 , V_13 -> V_18 ,
V_13 -> V_13 , V_13 -> V_19 ) ;
F_5 ( & V_8 -> V_20 ) ;
break;
case V_21 :
if ( V_4 != sizeof( * V_11 ) ) {
F_3 ( V_8 -> V_9 ,
L_3 ) ;
break;
}
V_11 = V_3 ;
V_8 -> V_22 = V_11 -> V_23 ;
F_5 ( & V_8 -> V_20 ) ;
break;
case V_24 :
F_6 ( V_8 -> V_9 , L_4 ) ;
F_5 ( & V_8 -> V_25 ) ;
break;
default:
F_4 ( V_8 -> V_9 , L_5 , V_15 -> type ) ;
break;
}
return 0 ;
}
static int F_7 ( struct V_7 * V_8 )
{
struct V_14 V_26 ;
int V_27 ;
V_26 . type = V_28 ;
V_26 . V_29 = sizeof( V_26 ) ;
V_27 = F_8 ( V_8 -> V_30 , & V_26 , sizeof( V_26 ) ) ;
if ( V_27 < 0 )
return V_27 ;
V_27 = F_9 ( & V_8 -> V_20 , V_31 ) ;
if ( ! V_27 ) {
F_3 ( V_8 -> V_9 , L_6 ) ;
return - V_32 ;
}
return 0 ;
}
static int F_10 ( struct V_7 * V_8 , bool * V_33 )
{
struct V_34 * V_35 ;
const struct V_36 * V_37 ;
const void * V_3 ;
T_2 V_38 ;
int V_27 ;
V_35 = F_11 ( sizeof( * V_35 ) + V_39 , V_40 ) ;
if ( ! V_35 )
return - V_41 ;
V_27 = F_12 ( & V_37 , V_42 , V_8 -> V_9 ) ;
if ( V_27 < 0 ) {
F_3 ( V_8 -> V_9 , L_7 ,
V_42 , V_27 ) ;
goto V_43;
}
V_3 = V_37 -> V_3 ;
V_38 = V_37 -> V_44 ;
V_35 -> V_15 . type = V_45 ;
V_35 -> V_15 . V_29 = sizeof( * V_35 ) + V_39 ;
V_35 -> V_46 = 0 ;
V_35 -> V_47 = V_39 ;
V_35 -> V_48 = 0 ;
do {
if ( V_38 <= V_39 ) {
V_35 -> V_46 = 1 ;
V_35 -> V_47 = V_38 ;
V_35 -> V_15 . V_29 = sizeof( * V_35 ) + V_38 ;
}
memcpy ( V_35 -> V_49 , V_3 , V_35 -> V_47 ) ;
V_27 = F_8 ( V_8 -> V_30 , V_35 , V_35 -> V_15 . V_29 ) ;
if ( V_27 < 0 ) {
F_3 ( V_8 -> V_9 , L_8 ) ;
goto V_50;
}
V_35 -> V_48 ++ ;
V_3 += V_35 -> V_15 . V_29 ;
V_38 -= V_39 ;
} while ( V_38 > 0 );
V_27 = F_9 ( & V_8 -> V_20 , V_51 ) ;
if ( ! V_27 ) {
F_3 ( V_8 -> V_9 , L_9 ) ;
V_27 = - V_32 ;
} else {
* V_33 = V_8 -> V_22 == V_52 ;
V_27 = 0 ;
}
V_50:
F_13 ( V_37 ) ;
V_43:
F_14 ( V_35 ) ;
return V_27 ;
}
struct V_53 * F_15 ( void * V_8 , const char * V_54 , T_3 V_55 , void * V_5 )
{
struct V_56 V_57 ;
struct V_7 * V_58 = V_8 ;
strncpy ( V_57 . V_54 , V_54 , sizeof( V_57 . V_54 ) ) ;
V_57 . V_59 = V_60 ;
V_57 . V_61 = V_60 ;
return F_16 ( V_58 -> V_30 -> V_2 , V_55 , V_5 , V_57 ) ;
}
static void F_17 ( struct V_62 * V_63 )
{
struct V_7 * V_8 = F_18 ( V_63 , struct V_7 , V_64 ) ;
bool V_33 ;
int V_27 ;
V_27 = F_7 ( V_8 ) ;
if ( V_27 < 0 )
return;
V_27 = F_10 ( V_8 , & V_33 ) ;
if ( V_27 < 0 )
return;
if ( V_33 ) {
V_27 = F_9 ( & V_8 -> V_25 , V_51 ) ;
if ( ! V_27 )
F_3 ( V_8 -> V_9 , L_10 ) ;
}
F_19 ( V_8 -> V_9 -> V_65 , NULL , NULL , V_8 -> V_9 ) ;
}
static int F_20 ( struct V_1 * V_2 )
{
struct V_7 * V_8 ;
V_8 = F_21 ( & V_2 -> V_9 , sizeof( * V_8 ) , V_40 ) ;
if ( ! V_8 )
return - V_41 ;
V_8 -> V_9 = & V_2 -> V_9 ;
V_8 -> V_30 = V_2 -> V_66 ;
F_22 ( & V_8 -> V_20 ) ;
F_22 ( & V_8 -> V_25 ) ;
F_23 ( & V_8 -> V_64 , F_17 ) ;
F_24 ( & V_2 -> V_9 , V_8 ) ;
F_25 ( & V_8 -> V_64 ) ;
return 0 ;
}
static void F_26 ( struct V_1 * V_2 )
{
struct V_7 * V_8 = F_2 ( & V_2 -> V_9 ) ;
F_27 ( & V_8 -> V_64 ) ;
F_28 ( & V_2 -> V_9 ) ;
}
