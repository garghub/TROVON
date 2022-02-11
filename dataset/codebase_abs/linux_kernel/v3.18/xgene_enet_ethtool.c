static void F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_7 * V_8 = V_6 -> V_8 ;
strcpy ( V_4 -> V_9 , L_1 ) ;
strcpy ( V_4 -> V_10 , V_11 ) ;
snprintf ( V_4 -> V_12 , V_13 , L_2 ) ;
sprintf ( V_4 -> V_14 , L_3 , V_8 -> V_15 ) ;
}
static int F_3 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_18 * V_19 = V_6 -> V_20 ;
if ( V_6 -> V_21 == V_22 ) {
if ( V_19 == NULL )
return - V_23 ;
return F_4 ( V_19 , V_17 ) ;
} else if ( V_6 -> V_21 == V_24 ) {
V_17 -> V_25 = V_26 |
V_27 | V_28 ;
V_17 -> V_29 = V_17 -> V_25 ;
F_5 ( V_17 , V_30 ) ;
V_17 -> V_31 = V_32 ;
V_17 -> V_33 = V_34 ;
V_17 -> V_35 = V_36 ;
V_17 -> V_37 = V_38 ;
} else {
V_17 -> V_25 = V_39 | V_40 ;
V_17 -> V_29 = V_17 -> V_25 ;
F_5 ( V_17 , V_41 ) ;
V_17 -> V_31 = V_32 ;
V_17 -> V_33 = V_42 ;
V_17 -> V_35 = V_36 ;
V_17 -> V_37 = V_43 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_18 * V_19 = V_6 -> V_20 ;
if ( V_6 -> V_21 == V_22 ) {
if ( V_19 == NULL )
return - V_23 ;
return F_7 ( V_19 , V_17 ) ;
}
return - V_44 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_45 , T_2 * V_46 )
{
int V_47 ;
T_2 * V_48 = V_46 ;
if ( V_45 != V_49 )
return;
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ ) {
memcpy ( V_48 , V_51 [ V_47 ] . V_15 , V_52 ) ;
V_48 += V_52 ;
}
}
static int F_9 ( struct V_1 * V_2 , int V_53 )
{
if ( V_53 != V_49 )
return - V_44 ;
return V_50 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_54 * V_55 ,
T_3 * V_46 )
{
void * V_6 = F_2 ( V_2 ) ;
int V_47 ;
for ( V_47 = 0 ; V_47 < V_50 ; V_47 ++ )
* V_46 ++ = * ( T_3 * ) ( V_6 + V_51 [ V_47 ] . V_56 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
V_2 -> V_57 = & V_58 ;
}
