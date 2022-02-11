static int
F_1 ( struct V_1 * V_2 , void T_1 * V_3 )
{
int V_4 ;
struct V_5 V_6 ;
if ( F_2 ( & V_6 , V_3 , sizeof( V_6 ) ) )
return - V_7 ;
if ( V_6 . type >= V_8 &&
V_6 . type <= V_9 ) {
V_4 = F_3 ( V_2 -> V_10 , V_3 , V_6 . V_11 + sizeof( V_6 ) , V_12 ) ;
if ( V_4 < 0 )
return V_4 ;
} else {
if ( V_2 -> V_13 . V_14 )
return V_2 -> V_13 . V_14 ( V_2 , V_6 . type , V_6 . V_15 , V_3 , V_6 . V_11 + sizeof( V_6 ) ) ;
else
return - V_16 ;
}
return 0 ;
}
static int
F_4 ( struct V_1 * V_2 , void T_1 * V_3 )
{
struct V_17 V_18 ;
int V_19 ;
if ( F_2 ( & V_18 , V_3 , sizeof( V_18 ) ) )
return - V_7 ;
if ( V_18 . V_20 < 0 || V_18 . V_20 >= V_21 )
return - V_16 ;
if ( V_18 . V_22 < 0 ) {
for ( V_19 = 0 ; V_19 < V_2 -> V_23 ; V_19 ++ )
V_2 -> V_24 [ V_19 ] -> V_25 [ V_18 . V_20 ] = V_18 . V_26 ;
} else {
if ( V_18 . V_22 < V_2 -> V_23 )
V_2 -> V_24 [ V_18 . V_22 ] -> V_25 [ V_18 . V_20 ] = V_18 . V_26 ;
}
return 0 ;
}
static int
F_5 ( struct V_27 * V_28 , struct V_29 * V_29 ,
unsigned int V_30 , unsigned long V_3 )
{
struct V_1 * V_2 = V_28 -> V_31 ;
switch ( V_30 ) {
case V_32 :
return F_6 ( V_33 , ( unsigned int T_1 * ) V_3 ) ;
case V_34 :
return F_1 ( V_2 , ( void T_1 * ) V_3 ) ;
case V_35 :
F_7 ( V_2 -> V_10 ) ;
break;
case V_36 :
F_8 ( V_2 -> V_10 ) ;
break;
case V_37 :
if ( V_2 -> V_38 ) {
int V_39 = F_9 ( V_2 -> V_38 ) ;
return F_6 ( V_39 , ( unsigned int T_1 * ) V_3 ) ;
}
break;
case V_40 :
return F_4 ( V_2 , ( void T_1 * ) V_3 ) ;
}
return 0 ;
}
int
F_10 ( struct V_1 * V_2 )
{
struct V_27 * V_28 ;
int V_4 ;
if ( ( V_4 = F_11 ( V_2 -> V_41 , V_42 , V_2 -> V_43 , & V_28 ) ) < 0 )
return V_4 ;
V_2 -> V_44 = V_28 ;
strcpy ( V_28 -> V_45 , V_42 ) ;
V_28 -> V_46 = V_47 ;
V_28 -> V_13 . V_48 = F_5 ;
V_28 -> V_13 . V_49 = F_5 ;
V_28 -> V_50 = 1 ;
V_28 -> V_31 = V_2 ;
if ( ( V_4 = F_12 ( V_2 -> V_41 ) ) < 0 )
return V_4 ;
return 0 ;
}
void
F_13 ( struct V_1 * V_2 )
{
if ( V_2 -> V_44 ) {
F_14 ( V_2 -> V_41 , V_2 -> V_44 ) ;
V_2 -> V_44 = NULL ;
}
}
