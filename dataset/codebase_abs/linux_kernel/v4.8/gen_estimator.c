static void F_1 ( unsigned long V_1 )
{
int V_2 = ( int ) V_1 ;
struct V_3 * V_4 ;
F_2 () ;
F_3 (e, &elist[idx].list, list) {
struct V_5 V_6 = { 0 } ;
unsigned long V_7 ;
T_1 V_8 ;
if ( V_4 -> V_9 )
F_4 ( V_4 -> V_9 ) ;
F_5 ( & V_10 ) ;
if ( V_4 -> V_11 == NULL )
goto V_12;
F_6 ( V_4 -> V_13 , & V_6 , V_4 -> V_14 , V_4 -> V_11 ) ;
V_8 = ( V_6 . V_15 - V_4 -> V_16 ) << ( 7 - V_2 ) ;
V_4 -> V_16 = V_6 . V_15 ;
V_4 -> V_17 += ( V_8 >> V_4 -> V_18 ) - ( V_4 -> V_17 >> V_4 -> V_18 ) ;
F_7 ( V_4 -> V_19 -> V_20 , ( V_4 -> V_17 + 0xF ) >> 5 ) ;
V_7 = V_6 . V_21 - V_4 -> V_22 ;
V_7 <<= ( 7 - V_2 ) ;
V_4 -> V_22 = V_6 . V_21 ;
V_4 -> V_23 += ( V_7 >> V_4 -> V_18 ) - ( V_4 -> V_23 >> V_4 -> V_18 ) ;
F_7 ( V_4 -> V_19 -> V_24 , ( V_4 -> V_23 + 0xF ) >> 5 ) ;
V_12:
F_8 ( & V_10 ) ;
if ( V_4 -> V_9 )
F_9 ( V_4 -> V_9 ) ;
}
if ( ! F_10 ( & V_25 [ V_2 ] . V_26 ) )
F_11 ( & V_25 [ V_2 ] . V_27 , V_28 + ( ( V_29 / 4 ) << V_2 ) ) ;
F_12 () ;
}
static void F_13 ( struct V_3 * V_30 )
{
struct V_31 * * V_32 = & V_33 . V_31 , * V_34 = NULL ;
while ( * V_32 ) {
struct V_3 * V_4 ;
V_34 = * V_32 ;
V_4 = F_14 ( V_34 , struct V_3 , V_35 ) ;
if ( V_30 -> V_11 > V_4 -> V_11 )
V_32 = & V_34 -> V_36 ;
else
V_32 = & V_34 -> V_37 ;
}
F_15 ( & V_30 -> V_35 , V_34 , V_32 ) ;
F_16 ( & V_30 -> V_35 , & V_33 ) ;
}
static
struct V_3 * F_17 ( const struct V_5 * V_11 ,
const struct V_38 * V_19 )
{
struct V_31 * V_32 = V_33 . V_31 ;
while ( V_32 ) {
struct V_3 * V_4 ;
V_4 = F_14 ( V_32 , struct V_3 , V_35 ) ;
if ( V_11 > V_4 -> V_11 )
V_32 = V_32 -> V_36 ;
else if ( V_11 < V_4 -> V_11 || V_19 != V_4 -> V_19 )
V_32 = V_32 -> V_37 ;
else
return V_4 ;
}
return NULL ;
}
int F_18 ( struct V_5 * V_11 ,
struct V_39 T_2 * V_14 ,
struct V_38 * V_19 ,
T_3 * V_9 ,
T_4 * V_13 ,
struct V_40 * V_41 )
{
struct V_3 * V_30 ;
struct V_42 * V_43 = F_19 ( V_41 ) ;
struct V_5 V_6 = { 0 } ;
int V_2 ;
if ( F_20 ( V_41 ) < sizeof( * V_43 ) )
return - V_44 ;
if ( V_43 -> V_45 < - 2 || V_43 -> V_45 > 3 )
return - V_44 ;
V_30 = F_21 ( sizeof( * V_30 ) , V_46 ) ;
if ( V_30 == NULL )
return - V_47 ;
F_6 ( V_13 , & V_6 , V_14 , V_11 ) ;
V_2 = V_43 -> V_45 + 2 ;
V_30 -> V_11 = V_11 ;
V_30 -> V_19 = V_19 ;
V_30 -> V_9 = V_9 ;
V_30 -> V_13 = V_13 ;
V_30 -> V_18 = V_43 -> V_18 ;
V_30 -> V_16 = V_6 . V_15 ;
V_30 -> V_17 = V_19 -> V_20 << 5 ;
V_30 -> V_22 = V_6 . V_21 ;
V_30 -> V_23 = V_19 -> V_24 << 10 ;
V_30 -> V_14 = V_14 ;
F_22 ( & V_48 ) ;
if ( ! V_25 [ V_2 ] . V_27 . V_49 ) {
F_23 ( & V_25 [ V_2 ] . V_26 ) ;
F_24 ( & V_25 [ V_2 ] . V_27 , F_1 , V_2 ) ;
}
if ( F_10 ( & V_25 [ V_2 ] . V_26 ) )
F_11 ( & V_25 [ V_2 ] . V_27 , V_28 + ( ( V_29 / 4 ) << V_2 ) ) ;
F_25 ( & V_30 -> V_26 , & V_25 [ V_2 ] . V_26 ) ;
F_13 ( V_30 ) ;
F_26 ( & V_48 ) ;
return 0 ;
}
void F_27 ( struct V_5 * V_11 ,
struct V_38 * V_19 )
{
struct V_3 * V_4 ;
F_22 ( & V_48 ) ;
while ( ( V_4 = F_17 ( V_11 , V_19 ) ) ) {
F_28 ( & V_4 -> V_35 , & V_33 ) ;
F_29 ( & V_10 ) ;
V_4 -> V_11 = NULL ;
F_30 ( & V_10 ) ;
F_31 ( & V_4 -> V_26 ) ;
F_32 ( V_4 , V_50 ) ;
}
F_26 ( & V_48 ) ;
}
int F_33 ( struct V_5 * V_11 ,
struct V_39 T_2 * V_14 ,
struct V_38 * V_19 ,
T_3 * V_9 ,
T_4 * V_13 , struct V_40 * V_41 )
{
F_27 ( V_11 , V_19 ) ;
return F_18 ( V_11 , V_14 , V_19 , V_9 , V_13 , V_41 ) ;
}
bool F_34 ( const struct V_5 * V_11 ,
const struct V_38 * V_19 )
{
bool V_51 ;
F_35 () ;
F_22 ( & V_48 ) ;
V_51 = F_17 ( V_11 , V_19 ) != NULL ;
F_26 ( & V_48 ) ;
return V_51 ;
}
