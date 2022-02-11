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
if ( V_6 -> V_25 ) {
if ( ! V_19 )
return - V_23 ;
return F_4 ( V_19 , V_17 ) ;
}
V_17 -> V_26 = V_27 | V_28 |
V_29 ;
V_17 -> V_30 = V_17 -> V_26 ;
F_5 ( V_17 , V_31 ) ;
V_17 -> V_32 = V_33 ;
V_17 -> V_34 = V_35 ;
V_17 -> V_36 = V_37 ;
V_17 -> V_38 = V_39 ;
} else {
V_17 -> V_26 = V_40 | V_41 ;
V_17 -> V_30 = V_17 -> V_26 ;
F_5 ( V_17 , V_42 ) ;
V_17 -> V_32 = V_33 ;
V_17 -> V_34 = V_43 ;
V_17 -> V_36 = V_37 ;
V_17 -> V_38 = V_44 ;
}
return 0 ;
}
static int F_6 ( struct V_1 * V_2 , struct V_16 * V_17 )
{
struct V_5 * V_6 = F_2 ( V_2 ) ;
struct V_18 * V_19 = V_6 -> V_20 ;
if ( V_6 -> V_21 == V_22 ) {
if ( ! V_19 )
return - V_23 ;
return F_7 ( V_19 , V_17 ) ;
}
if ( V_6 -> V_21 == V_24 ) {
if ( V_6 -> V_25 ) {
if ( ! V_19 )
return - V_23 ;
return F_7 ( V_19 , V_17 ) ;
}
}
return - V_45 ;
}
static void F_8 ( struct V_1 * V_2 , T_1 V_46 , T_2 * V_47 )
{
int V_48 ;
T_2 * V_49 = V_47 ;
if ( V_46 != V_50 )
return;
for ( V_48 = 0 ; V_48 < V_51 ; V_48 ++ ) {
memcpy ( V_49 , V_52 [ V_48 ] . V_15 , V_53 ) ;
V_49 += V_53 ;
}
}
static int F_9 ( struct V_1 * V_2 , int V_54 )
{
if ( V_54 != V_50 )
return - V_45 ;
return V_51 ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_55 * V_56 ,
T_3 * V_47 )
{
void * V_6 = F_2 ( V_2 ) ;
int V_48 ;
for ( V_48 = 0 ; V_48 < V_51 ; V_48 ++ )
* V_47 ++ = * ( T_3 * ) ( V_6 + V_52 [ V_48 ] . V_57 ) ;
}
void F_11 ( struct V_1 * V_2 )
{
V_2 -> V_58 = & V_59 ;
}
