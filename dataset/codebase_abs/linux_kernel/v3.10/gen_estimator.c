static void F_1 ( unsigned long V_1 )
{
int V_2 = ( int ) V_1 ;
struct V_3 * V_4 ;
F_2 () ;
F_3 (e, &elist[idx].list, list) {
T_1 V_5 ;
T_1 V_6 ;
T_2 V_7 ;
T_2 V_8 ;
F_4 ( V_4 -> V_9 ) ;
F_5 ( & V_10 ) ;
if ( V_4 -> V_11 == NULL )
goto V_12;
V_5 = V_4 -> V_11 -> V_13 ;
V_7 = V_4 -> V_11 -> V_14 ;
V_6 = ( V_5 - V_4 -> V_15 ) << ( 7 - V_2 ) ;
V_4 -> V_15 = V_5 ;
V_4 -> V_16 += ( V_6 >> V_4 -> V_17 ) - ( V_4 -> V_16 >> V_4 -> V_17 ) ;
V_4 -> V_18 -> V_19 = ( V_4 -> V_16 + 0xF ) >> 5 ;
V_8 = ( V_7 - V_4 -> V_20 ) << ( 12 - V_2 ) ;
V_4 -> V_20 = V_7 ;
V_4 -> V_21 += ( V_8 >> V_4 -> V_17 ) - ( V_4 -> V_21 >> V_4 -> V_17 ) ;
V_4 -> V_18 -> V_22 = ( V_4 -> V_21 + 0x1FF ) >> 10 ;
V_12:
F_6 ( & V_10 ) ;
F_7 ( V_4 -> V_9 ) ;
}
if ( ! F_8 ( & V_23 [ V_2 ] . V_24 ) )
F_9 ( & V_23 [ V_2 ] . V_25 , V_26 + ( ( V_27 / 4 ) << V_2 ) ) ;
F_10 () ;
}
static void F_11 ( struct V_3 * V_28 )
{
struct V_29 * * V_30 = & V_31 . V_29 , * V_32 = NULL ;
while ( * V_30 ) {
struct V_3 * V_4 ;
V_32 = * V_30 ;
V_4 = F_12 ( V_32 , struct V_3 , V_33 ) ;
if ( V_28 -> V_11 > V_4 -> V_11 )
V_30 = & V_32 -> V_34 ;
else
V_30 = & V_32 -> V_35 ;
}
F_13 ( & V_28 -> V_33 , V_32 , V_30 ) ;
F_14 ( & V_28 -> V_33 , & V_31 ) ;
}
static
struct V_3 * F_15 ( const struct V_36 * V_11 ,
const struct V_37 * V_18 )
{
struct V_29 * V_30 = V_31 . V_29 ;
while ( V_30 ) {
struct V_3 * V_4 ;
V_4 = F_12 ( V_30 , struct V_3 , V_33 ) ;
if ( V_11 > V_4 -> V_11 )
V_30 = V_30 -> V_34 ;
else if ( V_11 < V_4 -> V_11 || V_18 != V_4 -> V_18 )
V_30 = V_30 -> V_35 ;
else
return V_4 ;
}
return NULL ;
}
int F_16 ( struct V_36 * V_11 ,
struct V_37 * V_18 ,
T_3 * V_9 ,
struct V_38 * V_39 )
{
struct V_3 * V_28 ;
struct V_40 * V_41 = F_17 ( V_39 ) ;
int V_2 ;
if ( F_18 ( V_39 ) < sizeof( * V_41 ) )
return - V_42 ;
if ( V_41 -> V_43 < - 2 || V_41 -> V_43 > 3 )
return - V_42 ;
V_28 = F_19 ( sizeof( * V_28 ) , V_44 ) ;
if ( V_28 == NULL )
return - V_45 ;
V_2 = V_41 -> V_43 + 2 ;
V_28 -> V_11 = V_11 ;
V_28 -> V_18 = V_18 ;
V_28 -> V_9 = V_9 ;
V_28 -> V_17 = V_41 -> V_17 ;
V_28 -> V_15 = V_11 -> V_13 ;
V_28 -> V_16 = V_18 -> V_19 << 5 ;
V_28 -> V_20 = V_11 -> V_14 ;
V_28 -> V_21 = V_18 -> V_22 << 10 ;
F_20 ( & V_46 ) ;
if ( ! V_23 [ V_2 ] . V_25 . V_47 ) {
F_21 ( & V_23 [ V_2 ] . V_24 ) ;
F_22 ( & V_23 [ V_2 ] . V_25 , F_1 , V_2 ) ;
}
if ( F_8 ( & V_23 [ V_2 ] . V_24 ) )
F_9 ( & V_23 [ V_2 ] . V_25 , V_26 + ( ( V_27 / 4 ) << V_2 ) ) ;
F_23 ( & V_28 -> V_24 , & V_23 [ V_2 ] . V_24 ) ;
F_11 ( V_28 ) ;
F_24 ( & V_46 ) ;
return 0 ;
}
void F_25 ( struct V_36 * V_11 ,
struct V_37 * V_18 )
{
struct V_3 * V_4 ;
F_20 ( & V_46 ) ;
while ( ( V_4 = F_15 ( V_11 , V_18 ) ) ) {
F_26 ( & V_4 -> V_33 , & V_31 ) ;
F_27 ( & V_10 ) ;
V_4 -> V_11 = NULL ;
F_28 ( & V_10 ) ;
F_29 ( & V_4 -> V_24 ) ;
F_30 ( V_4 , V_48 ) ;
}
F_24 ( & V_46 ) ;
}
int F_31 ( struct V_36 * V_11 ,
struct V_37 * V_18 ,
T_3 * V_9 , struct V_38 * V_39 )
{
F_25 ( V_11 , V_18 ) ;
return F_16 ( V_11 , V_18 , V_9 , V_39 ) ;
}
bool F_32 ( const struct V_36 * V_11 ,
const struct V_37 * V_18 )
{
bool V_49 ;
F_33 () ;
F_20 ( & V_46 ) ;
V_49 = F_15 ( V_11 , V_18 ) != NULL ;
F_24 ( & V_46 ) ;
return V_49 ;
}
