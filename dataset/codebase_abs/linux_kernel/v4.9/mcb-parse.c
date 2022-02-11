static inline T_1 F_1 ( void T_2 * V_1 )
{
T_1 V_2 ;
V_2 = F_2 ( V_1 ) ;
return V_2 >> 28 ;
}
static int F_3 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
void T_2 * V_7 )
{
return 0 ;
}
static int F_4 ( struct V_3 * V_4 ,
struct V_5 * V_6 ,
void T_2 * V_7 , int V_8 )
{
struct V_9 T_2 * V_10 =
(struct V_9 T_2 * ) V_7 ;
struct V_11 * V_12 ;
T_3 V_13 ;
T_3 V_14 ;
T_3 V_15 ;
int V_16 ;
T_4 V_17 ;
T_4 V_18 ;
V_12 = F_5 ( V_4 ) ;
if ( ! V_12 )
return - V_19 ;
V_17 = F_2 ( & V_10 -> V_17 ) ;
V_18 = F_2 ( & V_10 -> V_18 ) ;
V_14 = F_2 ( & V_10 -> V_14 ) ;
V_15 = F_2 ( & V_10 -> V_15 ) ;
V_12 -> V_20 = F_6 ( V_17 ) ;
V_12 -> V_21 = F_7 ( V_17 ) ;
V_12 -> V_22 = F_8 ( V_17 ) ;
V_12 -> V_23 = F_9 ( V_18 ) ;
V_12 -> V_24 = F_10 ( V_18 ) ;
V_12 -> V_25 = F_11 ( V_18 ) ;
if ( V_12 -> V_23 > V_8 - 1 ) {
F_12 ( L_1 , V_12 -> V_20 ) ;
V_16 = 0 ;
goto V_26;
}
V_13 = V_6 [ V_12 -> V_23 ] . V_27 ;
if ( ! V_13 ) {
F_12 ( L_2 , V_12 -> V_20 ) ;
V_16 = 0 ;
goto V_26;
}
if ( V_13 & 0x01 ) {
F_12 ( L_3 ,
V_12 -> V_20 ) ;
V_16 = 0 ;
goto V_26;
}
F_13 ( L_4 , V_12 -> V_20 ) ;
V_12 -> V_28 . V_29 = F_14 ( V_17 ) ;
V_12 -> V_28 . V_30 = F_14 ( V_17 ) ;
V_12 -> V_28 . V_31 = V_32 ;
V_12 -> V_33 . V_29 = V_13 + V_14 ;
V_12 -> V_33 . V_30 = V_12 -> V_33 . V_29 + V_15 - 1 ;
V_12 -> V_33 . V_31 = V_34 ;
V_12 -> V_35 = false ;
V_16 = F_15 ( V_4 , V_12 ) ;
if ( V_16 < 0 )
goto V_26;
return 0 ;
V_26:
F_16 ( V_12 ) ;
return V_16 ;
}
static void F_17 ( void T_2 * V_7 ,
struct V_5 * V_6 , int V_8 )
{
char T_2 * V_1 = V_7 ;
int V_36 ;
V_1 += sizeof( T_4 ) ;
for ( V_36 = 0 ; V_36 < V_8 ; V_36 ++ ) {
V_6 [ V_36 ] . V_27 = F_2 ( V_1 ) ;
V_6 [ V_36 ] . V_15 = F_2 ( V_1 + 4 ) ;
V_1 += sizeof( struct V_5 ) ;
}
}
static int F_18 ( char T_2 * * V_7 , T_5 V_37 ,
struct V_5 * * V_6 )
{
struct V_5 * V_38 ;
int V_8 ;
T_4 V_39 ;
T_3 V_2 ;
V_2 = F_1 ( * V_7 ) ;
if ( V_2 == V_40 ) {
V_39 = F_2 ( * V_7 ) ;
V_8 = F_19 ( V_39 ) ;
if ( V_8 <= 0 && V_8 > V_41 )
return - V_42 ;
V_38 = F_20 ( V_8 , sizeof( struct V_5 ) ,
V_43 ) ;
if ( ! V_38 )
return - V_19 ;
F_17 ( * V_7 , V_38 , V_8 ) ;
* V_7 += F_21 ( V_8 ) ;
} else {
V_38 = F_22 ( sizeof( struct V_5 ) , V_43 ) ;
if ( ! V_38 )
return - V_19 ;
V_8 = 1 ;
V_38 -> V_27 = V_37 ;
}
* V_6 = V_38 ;
return V_8 ;
}
int F_23 ( struct V_3 * V_4 , T_5 V_37 ,
void T_2 * V_7 )
{
struct V_44 * V_45 ;
struct V_5 * V_6 ;
char T_2 * V_1 = V_7 ;
int V_46 = 0 ;
T_1 V_2 ;
int V_8 ;
int V_16 = 0 ;
T_3 V_47 ;
V_47 = sizeof( struct V_44 ) ;
V_45 = F_22 ( V_47 , V_43 ) ;
if ( ! V_45 )
return - V_19 ;
F_24 ( V_45 , V_1 , V_47 ) ;
V_45 -> V_48 = F_25 ( V_45 -> V_48 ) ;
if ( V_45 -> V_48 != V_49 ) {
F_26 ( L_5 ,
V_45 -> V_48 ) ;
V_16 = - V_42 ;
goto V_50;
}
V_1 += V_47 ;
V_4 -> V_51 = V_45 -> V_51 ;
V_4 -> V_52 = V_45 -> V_52 ;
V_4 -> V_53 = V_45 -> V_53 ;
snprintf ( V_4 -> V_54 , V_55 + 1 , L_6 ,
V_45 -> V_56 ) ;
V_8 = F_18 ( & V_1 , V_37 , & V_6 ) ;
if ( V_8 < 0 )
goto V_50;
F_27 (dtype, p) {
switch ( V_2 ) {
case V_57 :
V_16 = F_4 ( V_4 , V_6 , V_1 , V_8 ) ;
if ( V_16 < 0 )
goto V_58;
V_1 += sizeof( struct V_9 ) ;
break;
case V_59 :
F_3 ( V_4 , V_6 , V_1 ) ;
V_1 += sizeof( struct V_60 ) ;
break;
case V_61 :
break;
default:
F_26 ( L_7 ,
V_2 ) ;
V_16 = - V_62 ;
goto V_58;
}
V_46 ++ ;
}
if ( V_46 == 0 )
V_46 = - V_62 ;
F_28 ( V_6 ) ;
F_28 ( V_45 ) ;
return V_46 ;
V_58:
F_28 ( V_6 ) ;
V_50:
F_28 ( V_45 ) ;
return V_16 ;
}
