static void F_1 ( unsigned long V_1 )
{
int V_2 = ( int ) V_1 ;
struct V_3 * V_4 ;
F_2 () ;
F_3 (e, &elist[idx].list, list) {
struct V_5 V_6 = { 0 } ;
unsigned long V_7 ;
T_1 V_8 ;
F_4 ( V_4 -> V_9 ) ;
F_5 ( & V_10 ) ;
if ( V_4 -> V_11 == NULL )
goto V_12;
F_6 ( & V_6 , V_4 -> V_13 , V_4 -> V_11 ) ;
V_8 = ( V_6 . V_14 - V_4 -> V_15 ) << ( 7 - V_2 ) ;
V_4 -> V_15 = V_6 . V_14 ;
V_4 -> V_16 += ( V_8 >> V_4 -> V_17 ) - ( V_4 -> V_16 >> V_4 -> V_17 ) ;
V_4 -> V_18 -> V_19 = ( V_4 -> V_16 + 0xF ) >> 5 ;
V_7 = V_6 . V_20 - V_4 -> V_21 ;
V_7 <<= ( 7 - V_2 ) ;
V_4 -> V_21 = V_6 . V_20 ;
V_4 -> V_22 += ( V_7 >> V_4 -> V_17 ) - ( V_4 -> V_22 >> V_4 -> V_17 ) ;
V_4 -> V_18 -> V_23 = ( V_4 -> V_22 + 0xF ) >> 5 ;
V_12:
F_7 ( & V_10 ) ;
F_8 ( V_4 -> V_9 ) ;
}
if ( ! F_9 ( & V_24 [ V_2 ] . V_25 ) )
F_10 ( & V_24 [ V_2 ] . V_26 , V_27 + ( ( V_28 / 4 ) << V_2 ) ) ;
F_11 () ;
}
static void F_12 ( struct V_3 * V_29 )
{
struct V_30 * * V_31 = & V_32 . V_30 , * V_33 = NULL ;
while ( * V_31 ) {
struct V_3 * V_4 ;
V_33 = * V_31 ;
V_4 = F_13 ( V_33 , struct V_3 , V_34 ) ;
if ( V_29 -> V_11 > V_4 -> V_11 )
V_31 = & V_33 -> V_35 ;
else
V_31 = & V_33 -> V_36 ;
}
F_14 ( & V_29 -> V_34 , V_33 , V_31 ) ;
F_15 ( & V_29 -> V_34 , & V_32 ) ;
}
static
struct V_3 * F_16 ( const struct V_5 * V_11 ,
const struct V_37 * V_18 )
{
struct V_30 * V_31 = V_32 . V_30 ;
while ( V_31 ) {
struct V_3 * V_4 ;
V_4 = F_13 ( V_31 , struct V_3 , V_34 ) ;
if ( V_11 > V_4 -> V_11 )
V_31 = V_31 -> V_35 ;
else if ( V_11 < V_4 -> V_11 || V_18 != V_4 -> V_18 )
V_31 = V_31 -> V_36 ;
else
return V_4 ;
}
return NULL ;
}
int F_17 ( struct V_5 * V_11 ,
struct V_38 T_2 * V_13 ,
struct V_37 * V_18 ,
T_3 * V_9 ,
struct V_39 * V_40 )
{
struct V_3 * V_29 ;
struct V_41 * V_42 = F_18 ( V_40 ) ;
struct V_5 V_6 = { 0 } ;
int V_2 ;
if ( F_19 ( V_40 ) < sizeof( * V_42 ) )
return - V_43 ;
if ( V_42 -> V_44 < - 2 || V_42 -> V_44 > 3 )
return - V_43 ;
V_29 = F_20 ( sizeof( * V_29 ) , V_45 ) ;
if ( V_29 == NULL )
return - V_46 ;
F_6 ( & V_6 , V_13 , V_11 ) ;
V_2 = V_42 -> V_44 + 2 ;
V_29 -> V_11 = V_11 ;
V_29 -> V_18 = V_18 ;
V_29 -> V_9 = V_9 ;
V_29 -> V_17 = V_42 -> V_17 ;
V_29 -> V_15 = V_6 . V_14 ;
V_29 -> V_16 = V_18 -> V_19 << 5 ;
V_29 -> V_21 = V_6 . V_20 ;
V_29 -> V_22 = V_18 -> V_23 << 10 ;
V_29 -> V_13 = V_13 ;
F_21 ( & V_47 ) ;
if ( ! V_24 [ V_2 ] . V_26 . V_48 ) {
F_22 ( & V_24 [ V_2 ] . V_25 ) ;
F_23 ( & V_24 [ V_2 ] . V_26 , F_1 , V_2 ) ;
}
if ( F_9 ( & V_24 [ V_2 ] . V_25 ) )
F_10 ( & V_24 [ V_2 ] . V_26 , V_27 + ( ( V_28 / 4 ) << V_2 ) ) ;
F_24 ( & V_29 -> V_25 , & V_24 [ V_2 ] . V_25 ) ;
F_12 ( V_29 ) ;
F_25 ( & V_47 ) ;
return 0 ;
}
void F_26 ( struct V_5 * V_11 ,
struct V_37 * V_18 )
{
struct V_3 * V_4 ;
F_21 ( & V_47 ) ;
while ( ( V_4 = F_16 ( V_11 , V_18 ) ) ) {
F_27 ( & V_4 -> V_34 , & V_32 ) ;
F_28 ( & V_10 ) ;
V_4 -> V_11 = NULL ;
F_29 ( & V_10 ) ;
F_30 ( & V_4 -> V_25 ) ;
F_31 ( V_4 , V_49 ) ;
}
F_25 ( & V_47 ) ;
}
int F_32 ( struct V_5 * V_11 ,
struct V_38 T_2 * V_13 ,
struct V_37 * V_18 ,
T_3 * V_9 , struct V_39 * V_40 )
{
F_26 ( V_11 , V_18 ) ;
return F_17 ( V_11 , V_13 , V_18 , V_9 , V_40 ) ;
}
bool F_33 ( const struct V_5 * V_11 ,
const struct V_37 * V_18 )
{
bool V_50 ;
F_34 () ;
F_21 ( & V_47 ) ;
V_50 = F_16 ( V_11 , V_18 ) != NULL ;
F_25 ( & V_47 ) ;
return V_50 ;
}
