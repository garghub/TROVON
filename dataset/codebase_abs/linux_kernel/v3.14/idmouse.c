static int F_1 ( struct V_1 * V_2 )
{
int V_3 ;
int V_4 ;
int V_5 ;
memcpy ( V_2 -> V_6 , V_7 , sizeof( V_7 ) - 1 ) ;
V_3 = sizeof( V_7 ) - 1 ;
V_5 = F_2 ( V_2 , V_8 , 0 , 0 ) ;
if ( V_5 < 0 )
goto V_9;
V_5 = F_2 ( V_2 , V_10 , 1 , 0 ) ;
if ( V_5 < 0 )
goto V_9;
V_5 = F_2 ( V_2 , V_11 , 0 , 0 ) ;
if ( V_5 < 0 )
goto V_9;
V_5 = F_2 ( V_2 , V_11 , 0 , 0 ) ;
if ( V_5 < 0 )
goto V_9;
V_5 = F_2 ( V_2 , V_12 , 0 , 0 ) ;
if ( V_5 < 0 )
goto V_9;
V_5 = F_2 ( V_2 , V_12 , 0 , 0 ) ;
if ( V_5 < 0 )
goto V_9;
while ( V_3 < V_13 ) {
V_5 = F_3 ( V_2 -> V_14 ,
F_4 ( V_2 -> V_14 , V_2 -> V_15 ) ,
V_2 -> V_6 + V_3 ,
V_2 -> V_16 , & V_4 , 5000 ) ;
if ( V_5 < 0 ) {
if ( V_2 -> V_16 != V_2 -> V_17 ) {
V_2 -> V_16 = V_2 -> V_17 ;
V_5 = - V_18 ;
}
break;
}
if ( F_5 ( V_19 ) ) {
V_5 = - V_20 ;
break;
}
V_3 += V_4 ;
}
V_9:
F_2 ( V_2 , V_8 , 0 , 0 ) ;
for ( V_3 = sizeof( V_7 ) - 1 + V_21 - 1 ; V_3 < V_13 ; V_3 += V_21 )
if ( V_2 -> V_6 [ V_3 ] != 0x00 )
return - V_18 ;
for ( V_3 = V_13 - V_21 ; V_3 < V_13 - 1 ; V_3 ++ )
if ( V_2 -> V_6 [ V_3 ] != 0xFF )
return - V_18 ;
F_6 ( & V_2 -> V_22 -> V_2 , L_1 ,
V_3 ) ;
return V_5 ;
}
static int F_7 ( struct V_23 * V_24 , T_1 V_25 )
{
return 0 ;
}
static int F_8 ( struct V_23 * V_24 )
{
return 0 ;
}
static inline void F_9 ( struct V_1 * V_2 )
{
F_10 ( V_2 -> V_6 ) ;
F_10 ( V_2 ) ;
}
static int F_11 ( struct V_26 * V_26 , struct V_27 * V_27 )
{
struct V_1 * V_2 ;
struct V_23 * V_22 ;
int V_5 ;
V_22 = F_12 ( & V_28 , F_13 ( V_26 ) ) ;
if ( ! V_22 )
return - V_29 ;
F_14 ( & V_30 ) ;
V_2 = F_15 ( V_22 ) ;
if ( ! V_2 ) {
F_16 ( & V_30 ) ;
return - V_29 ;
}
F_14 ( & V_2 -> V_31 ) ;
F_16 ( & V_30 ) ;
if ( V_2 -> V_32 ) {
V_5 = - V_33 ;
} else {
V_5 = F_17 ( V_22 ) ;
if ( V_5 )
goto error;
V_5 = F_1 ( V_2 ) ;
if ( V_5 )
goto error;
F_18 ( V_22 ) ;
++ V_2 -> V_32 ;
V_27 -> V_34 = V_2 ;
}
error:
F_16 ( & V_2 -> V_31 ) ;
return V_5 ;
}
static int F_19 ( struct V_26 * V_26 , struct V_27 * V_27 )
{
struct V_1 * V_2 ;
V_2 = V_27 -> V_34 ;
if ( V_2 == NULL )
return - V_29 ;
F_14 ( & V_30 ) ;
F_14 ( & V_2 -> V_31 ) ;
if ( V_2 -> V_32 <= 0 ) {
F_16 ( & V_2 -> V_31 ) ;
F_16 ( & V_30 ) ;
return - V_29 ;
}
-- V_2 -> V_32 ;
if ( ! V_2 -> V_35 ) {
F_16 ( & V_2 -> V_31 ) ;
F_16 ( & V_30 ) ;
F_9 ( V_2 ) ;
} else {
F_16 ( & V_2 -> V_31 ) ;
F_16 ( & V_30 ) ;
}
return 0 ;
}
static T_2 F_20 ( struct V_27 * V_27 , char T_3 * V_36 , T_4 V_37 ,
T_5 * V_38 )
{
struct V_1 * V_2 = V_27 -> V_34 ;
int V_5 ;
F_14 ( & V_2 -> V_31 ) ;
if ( ! V_2 -> V_35 ) {
F_16 ( & V_2 -> V_31 ) ;
return - V_29 ;
}
V_5 = F_21 ( V_36 , V_37 , V_38 ,
V_2 -> V_6 , V_13 ) ;
F_16 ( & V_2 -> V_31 ) ;
return V_5 ;
}
static int F_22 ( struct V_23 * V_22 ,
const struct V_39 * V_40 )
{
struct V_41 * V_14 = F_23 ( V_22 ) ;
struct V_1 * V_2 ;
struct V_42 * V_43 ;
struct V_44 * V_45 ;
int V_5 ;
V_43 = & V_22 -> V_46 [ 0 ] ;
if ( V_43 -> V_47 . V_48 != 0x0A )
return - V_29 ;
V_2 = F_24 ( sizeof( * V_2 ) , V_49 ) ;
if ( V_2 == NULL )
return - V_50 ;
F_25 ( & V_2 -> V_31 ) ;
V_2 -> V_14 = V_14 ;
V_2 -> V_22 = V_22 ;
V_45 = & V_43 -> V_45 [ 0 ] . V_47 ;
if ( ! V_2 -> V_15 && F_26 ( V_45 ) ) {
V_2 -> V_17 = F_27 ( V_45 ) ;
V_2 -> V_16 = 0x200 ;
V_2 -> V_15 = V_45 -> V_51 ;
V_2 -> V_6 =
F_28 ( V_13 + V_2 -> V_16 , V_49 ) ;
if ( ! V_2 -> V_6 ) {
F_29 ( & V_22 -> V_2 , L_2 ) ;
F_9 ( V_2 ) ;
return - V_50 ;
}
}
if ( ! ( V_2 -> V_15 ) ) {
F_29 ( & V_22 -> V_2 , L_3 ) ;
F_9 ( V_2 ) ;
return - V_29 ;
}
V_2 -> V_35 = 1 ;
F_30 ( V_22 , V_2 ) ;
V_5 = F_31 ( V_22 , & V_52 ) ;
if ( V_5 ) {
F_29 ( & V_22 -> V_2 , L_4 ) ;
F_30 ( V_22 , NULL ) ;
F_9 ( V_2 ) ;
return V_5 ;
}
F_32 ( & V_22 -> V_2 , L_5 , V_53 ) ;
return 0 ;
}
static void F_33 ( struct V_23 * V_22 )
{
struct V_1 * V_2 ;
V_2 = F_15 ( V_22 ) ;
F_34 ( V_22 , & V_52 ) ;
F_14 ( & V_30 ) ;
F_30 ( V_22 , NULL ) ;
F_14 ( & V_2 -> V_31 ) ;
F_16 ( & V_30 ) ;
V_2 -> V_35 = 0 ;
if ( ! V_2 -> V_32 ) {
F_16 ( & V_2 -> V_31 ) ;
F_9 ( V_2 ) ;
} else {
F_16 ( & V_2 -> V_31 ) ;
}
F_32 ( & V_22 -> V_2 , L_6 ) ;
}
