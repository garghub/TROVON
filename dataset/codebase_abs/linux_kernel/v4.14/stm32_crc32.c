static int F_1 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = V_6 ;
V_4 -> V_7 = V_8 ;
return 0 ;
}
static int F_3 ( struct V_1 * V_2 )
{
struct V_3 * V_4 = F_2 ( V_2 ) ;
V_4 -> V_5 = V_6 ;
V_4 -> V_7 = V_9 ;
return 0 ;
}
static int F_4 ( struct V_10 * V_2 , const T_1 * V_5 ,
unsigned int V_11 )
{
struct V_3 * V_4 = F_5 ( V_2 ) ;
if ( V_11 != sizeof( V_12 ) ) {
F_6 ( V_2 , V_13 ) ;
return - V_14 ;
}
V_4 -> V_5 = F_7 ( V_5 ) ;
return 0 ;
}
static int F_8 ( struct V_15 * V_16 )
{
struct V_17 * V_18 = F_9 ( V_16 ) ;
struct V_3 * V_4 = F_5 ( V_16 -> V_2 ) ;
struct V_19 * V_20 ;
F_10 ( & V_21 . V_22 ) ;
F_11 (crc, &crc_list.dev_list, list) {
V_18 -> V_20 = V_20 ;
break;
}
F_12 ( & V_21 . V_22 ) ;
F_13 ( F_14 ( V_4 -> V_5 ) , V_18 -> V_20 -> V_23 + V_24 ) ;
F_13 ( F_14 ( V_4 -> V_7 ) , V_18 -> V_20 -> V_23 + V_25 ) ;
F_13 ( V_26 | V_27 , V_18 -> V_20 -> V_23 + V_28 ) ;
V_18 -> V_29 = F_15 ( V_18 -> V_20 -> V_23 + V_30 ) ;
V_18 -> V_20 -> V_31 = 0 ;
return 0 ;
}
static int F_16 ( struct V_15 * V_16 , const T_1 * V_32 ,
unsigned int V_33 )
{
struct V_17 * V_18 = F_9 ( V_16 ) ;
struct V_19 * V_20 = V_18 -> V_20 ;
V_12 * V_34 ;
unsigned int V_35 ;
if ( F_17 ( V_20 -> V_31 ) ) {
while ( V_20 -> V_31 != sizeof( V_12 ) && V_33 ) {
V_20 -> V_36 [ V_20 -> V_31 ++ ] = * ( V_32 ++ ) ;
V_33 -- ;
}
if ( V_20 -> V_31 == sizeof( V_12 ) ) {
F_13 ( * ( V_12 * ) V_20 -> V_36 ,
V_20 -> V_23 + V_30 ) ;
V_20 -> V_31 = 0 ;
}
}
V_34 = ( V_12 * ) V_32 ;
for ( V_35 = 0 ; V_35 < V_33 > > 2 ; V_35 ++ )
F_13 ( * ( V_34 ++ ) , V_20 -> V_23 + V_30 ) ;
V_18 -> V_29 = F_15 ( V_20 -> V_23 + V_30 ) ;
V_33 &= 3 ;
if ( F_18 ( ! V_33 ) )
return 0 ;
if ( ( V_20 -> V_31 + V_33 ) >= sizeof( V_12 ) ) {
F_19 ( V_20 -> V_37 , L_1 ) ;
return - V_14 ;
}
V_32 = ( const T_1 * ) V_34 ;
for ( V_35 = 0 ; V_35 < V_33 ; V_35 ++ )
V_20 -> V_36 [ V_20 -> V_31 ++ ] = * ( V_32 ++ ) ;
return 0 ;
}
static int F_20 ( struct V_15 * V_16 , T_1 * V_38 )
{
struct V_17 * V_18 = F_9 ( V_16 ) ;
struct V_3 * V_4 = F_5 ( V_16 -> V_2 ) ;
F_21 ( V_4 -> V_7 == V_9 ?
~ V_18 -> V_29 : V_18 -> V_29 , V_38 ) ;
return 0 ;
}
static int F_22 ( struct V_15 * V_16 , const T_1 * V_39 ,
unsigned int V_33 , T_1 * V_38 )
{
return F_16 ( V_16 , V_39 , V_33 ) ? :
F_20 ( V_16 , V_38 ) ;
}
static int F_23 ( struct V_15 * V_16 , const T_1 * V_39 ,
unsigned int V_33 , T_1 * V_38 )
{
return F_8 ( V_16 ) ? : F_22 ( V_16 , V_39 , V_33 , V_38 ) ;
}
static int F_24 ( struct V_40 * V_41 )
{
struct V_42 * V_37 = & V_41 -> V_37 ;
struct V_19 * V_20 ;
struct V_43 * V_44 ;
int V_45 ;
V_20 = F_25 ( V_37 , sizeof( * V_20 ) , V_46 ) ;
if ( ! V_20 )
return - V_47 ;
V_20 -> V_37 = V_37 ;
V_44 = F_26 ( V_41 , V_48 , 0 ) ;
V_20 -> V_23 = F_27 ( V_37 , V_44 ) ;
if ( F_28 ( V_20 -> V_23 ) ) {
F_19 ( V_37 , L_2 ) ;
return F_29 ( V_20 -> V_23 ) ;
}
V_20 -> V_49 = F_30 ( V_37 , NULL ) ;
if ( F_28 ( V_20 -> V_49 ) ) {
F_19 ( V_37 , L_3 ) ;
return F_29 ( V_20 -> V_49 ) ;
}
V_45 = F_31 ( V_20 -> V_49 ) ;
if ( V_45 ) {
F_19 ( V_20 -> V_37 , L_4 ) ;
return V_45 ;
}
F_32 ( V_41 , V_20 ) ;
F_33 ( & V_21 . V_22 ) ;
F_34 ( & V_20 -> V_50 , & V_21 . V_51 ) ;
F_35 ( & V_21 . V_22 ) ;
V_45 = F_36 ( V_52 , F_37 ( V_52 ) ) ;
if ( V_45 ) {
F_19 ( V_37 , L_5 ) ;
F_38 ( V_20 -> V_49 ) ;
return V_45 ;
}
F_39 ( V_37 , L_6 ) ;
return 0 ;
}
static int F_40 ( struct V_40 * V_41 )
{
struct V_19 * V_20 = F_41 ( V_41 ) ;
F_33 ( & V_21 . V_22 ) ;
F_42 ( & V_20 -> V_50 ) ;
F_35 ( & V_21 . V_22 ) ;
F_43 ( V_52 , F_37 ( V_52 ) ) ;
F_38 ( V_20 -> V_49 ) ;
return 0 ;
}
