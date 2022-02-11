int F_1 ( struct V_1 * V_2 , struct V_3 * V_4 ,
T_1 V_5 , bool V_6 )
{
T_1 V_7 ;
if ( V_5 > V_8 )
return - V_9 ;
memset ( V_4 , 0 , sizeof( * V_4 ) ) ;
V_4 -> V_10 = F_2 ( & V_2 -> V_11 -> V_2 , V_12 ,
& V_4 -> V_13 , V_14 ) ;
if ( ! V_4 -> V_10 )
goto V_15;
V_4 -> V_16 = F_3 ( V_5 - 1 ) + 1 ;
V_4 -> V_17 = F_4 ( V_4 -> V_16 , sizeof( * V_4 -> V_17 ) ,
V_14 ) ;
if ( ! V_4 -> V_17 )
goto V_15;
for ( V_7 = 0 ; V_7 < V_4 -> V_16 ; V_7 ++ ) {
V_4 -> V_17 [ V_7 ] = F_2 ( & V_2 -> V_11 -> V_2 , V_12 ,
( V_18 * ) & V_4 -> V_10 [ V_7 ] ,
V_14 ) ;
if ( ! V_4 -> V_17 [ V_7 ] )
goto V_15;
}
V_4 -> V_5 = V_5 ;
if ( V_6 ) {
V_4 -> V_19 = F_4 ( V_5 , sizeof( * V_4 -> V_19 ) ,
V_14 ) ;
if ( ! V_4 -> V_19 )
goto V_15;
for ( V_7 = 0 ; V_7 < V_4 -> V_5 ; V_7 ++ ) {
V_18 V_20 ;
V_4 -> V_19 [ V_7 ] = F_2 ( & V_2 -> V_11 -> V_2 ,
V_12 ,
& V_20 ,
V_14 ) ;
if ( ! V_4 -> V_19 [ V_7 ] )
goto V_15;
F_5 ( V_4 , V_7 , V_20 ) ;
}
}
return 0 ;
V_15:
F_6 ( V_2 , V_4 ) ;
return - V_21 ;
}
static T_1 * F_7 ( struct V_3 * V_4 , T_1 V_22 )
{
return V_4 -> V_17 [ F_3 ( V_22 ) ] ;
}
V_18 F_8 ( struct V_3 * V_4 , T_1 V_22 )
{
return F_7 ( V_4 , V_22 ) [ F_9 ( V_22 ) ] ;
}
static void F_10 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_19 ) {
T_1 V_7 ;
for ( V_7 = 0 ; V_7 < V_4 -> V_5 && V_4 -> V_19 [ V_7 ] ; V_7 ++ ) {
V_18 V_20 = F_8 ( V_4 , V_7 ) ;
F_11 ( & V_2 -> V_11 -> V_2 , V_12 ,
V_4 -> V_19 [ V_7 ] , V_20 ) ;
}
F_12 ( V_4 -> V_19 ) ;
}
}
static void F_13 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_17 ) {
int V_7 ;
F_10 ( V_2 , V_4 ) ;
for ( V_7 = 0 ; V_7 < V_4 -> V_16 ; V_7 ++ ) {
T_1 * V_23 = V_4 -> V_17 [ V_7 ] ;
if ( V_23 )
F_11 ( & V_2 -> V_11 -> V_2 , V_12 ,
V_23 , V_4 -> V_10 [ V_7 ] ) ;
}
F_12 ( V_4 -> V_17 ) ;
}
}
void F_6 ( struct V_1 * V_2 ,
struct V_3 * V_4 )
{
if ( V_4 -> V_10 ) {
F_13 ( V_2 , V_4 ) ;
F_11 ( & V_2 -> V_11 -> V_2 , V_12 ,
V_4 -> V_10 , V_4 -> V_13 ) ;
}
}
int F_5 ( struct V_3 * V_4 , T_1 V_22 ,
V_18 V_24 )
{
T_1 * V_23 ;
if ( V_22 >= V_4 -> V_5 )
return - V_9 ;
V_23 = F_7 ( V_4 , V_22 ) ;
V_23 [ F_9 ( V_22 ) ] = V_24 ;
return 0 ;
}
int F_14 ( struct V_3 * V_4 ,
struct V_25 * V_26 , T_1 V_27 )
{
T_1 V_7 = V_27 ;
int V_28 , V_29 ;
int V_30 = 0 , V_31 = 0 ;
struct V_32 * V_33 ;
if ( V_27 >= V_4 -> V_5 )
return - V_9 ;
F_15 (umem->sg_head.sgl, sg, umem->nmap, entry) {
V_31 = F_16 ( V_33 ) >> V_34 ;
for ( V_28 = 0 ; V_28 < V_31 ; V_28 ++ ) {
V_18 V_35 = F_17 ( V_33 ) +
( V_28 << V_26 -> V_36 ) ;
V_30 = F_5 ( V_4 , V_7 , V_35 ) ;
if ( V_30 )
goto exit;
V_7 ++ ;
}
}
exit:
return V_30 ;
}
int F_18 ( struct V_3 * V_4 ,
T_1 * V_37 ,
int V_38 )
{
int V_7 ;
int V_30 ;
if ( V_38 > V_4 -> V_5 )
return - V_9 ;
for ( V_7 = 0 ; V_7 < V_38 ; V_7 ++ ) {
V_30 = F_5 ( V_4 , V_7 , V_37 [ V_7 ] ) ;
if ( V_30 )
return V_30 ;
}
return 0 ;
}
void F_19 ( struct V_39 * V_40 , const struct V_41 * V_42 )
{
V_40 -> V_43 = V_42 -> V_43 ;
V_40 -> V_44 = V_42 -> V_44 ;
V_40 -> V_45 = V_42 -> V_45 ;
V_40 -> V_46 = V_42 -> V_46 ;
V_40 -> V_47 = V_42 -> V_47 ;
}
void F_20 ( struct V_41 * V_40 , const struct V_39 * V_42 )
{
V_40 -> V_43 = V_42 -> V_43 ;
V_40 -> V_44 = V_42 -> V_44 ;
V_40 -> V_45 = V_42 -> V_45 ;
V_40 -> V_46 = V_42 -> V_46 ;
V_40 -> V_47 = V_42 -> V_47 ;
}
void F_21 ( union V_48 * V_40 , const union V_49 * V_42 )
{
F_22 ( sizeof( union V_49 ) != sizeof( union V_48 ) ) ;
memcpy ( V_40 , V_42 , sizeof( * V_42 ) ) ;
}
void F_23 ( union V_49 * V_40 , const union V_48 * V_42 )
{
F_22 ( sizeof( union V_49 ) != sizeof( union V_48 ) ) ;
memcpy ( V_40 , V_42 , sizeof( * V_42 ) ) ;
}
void F_24 ( struct V_50 * V_40 ,
const struct V_51 * V_42 )
{
F_21 ( & V_40 -> V_52 , & V_42 -> V_52 ) ;
V_40 -> V_53 = V_42 -> V_53 ;
V_40 -> V_54 = V_42 -> V_54 ;
V_40 -> V_55 = V_42 -> V_55 ;
V_40 -> V_56 = V_42 -> V_56 ;
}
void F_25 ( struct V_51 * V_40 ,
const struct V_50 * V_42 )
{
F_23 ( & V_40 -> V_52 , & V_42 -> V_52 ) ;
V_40 -> V_53 = V_42 -> V_53 ;
V_40 -> V_54 = V_42 -> V_54 ;
V_40 -> V_55 = V_42 -> V_55 ;
V_40 -> V_56 = V_42 -> V_56 ;
}
void F_26 ( struct V_57 * V_40 ,
const struct V_58 * V_42 )
{
V_40 -> type = V_59 ;
F_24 ( F_27 ( V_40 ) , & V_42 -> V_60 ) ;
F_28 ( V_40 , V_42 -> V_61 ) ;
F_29 ( V_40 , V_42 -> V_62 ) ;
F_30 ( V_40 , V_42 -> V_63 ) ;
F_31 ( V_40 , V_42 -> V_64 ) ;
F_32 ( V_40 , V_42 -> V_65 ) ;
F_33 ( V_40 , V_42 -> V_66 ) ;
memcpy ( V_40 -> V_67 . V_68 , & V_42 -> V_68 , V_69 ) ;
}
void F_34 ( struct V_58 * V_40 ,
const struct V_57 * V_42 )
{
F_25 ( & V_40 -> V_60 , F_35 ( V_42 ) ) ;
V_40 -> V_61 = F_36 ( V_42 ) ;
V_40 -> V_62 = F_37 ( V_42 ) ;
V_40 -> V_63 = F_38 ( V_42 ) ;
V_40 -> V_64 = F_39 ( V_42 ) ;
V_40 -> V_65 = F_40 ( V_42 ) ;
V_40 -> V_66 = F_41 ( V_42 ) ;
memcpy ( & V_40 -> V_68 , V_42 -> V_67 . V_68 , sizeof( V_40 -> V_68 ) ) ;
}
