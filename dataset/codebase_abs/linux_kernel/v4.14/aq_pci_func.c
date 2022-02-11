struct V_1 * F_1 ( struct V_2 * V_2 ,
struct V_3 * V_4 ,
const struct V_5 * V_6 ,
const struct V_7 * V_8 )
{
struct V_1 * V_9 = NULL ;
int V_10 = 0 ;
unsigned int V_11 = 0U ;
if ( ! V_2 ) {
V_10 = - V_12 ;
goto V_13;
}
V_9 = F_2 ( sizeof( * V_9 ) , V_14 ) ;
if ( ! V_9 ) {
V_10 = - V_15 ;
goto V_13;
}
F_3 ( V_4 , V_9 ) ;
V_9 -> V_4 = V_4 ;
V_10 = V_2 -> V_16 ( NULL , & V_9 -> V_17 ) ;
if ( V_10 < 0 )
goto V_13;
V_9 -> V_18 = V_9 -> V_17 . V_18 ;
for ( V_11 = 0 ; V_11 < V_9 -> V_18 ; ++ V_11 ) {
struct V_19 * V_20 = F_4 ( V_6 , V_8 ,
& V_4 -> V_21 , V_9 ,
V_11 , V_2 ) ;
if ( ! V_20 ) {
V_10 = - V_15 ;
goto V_13;
}
V_9 -> V_11 [ V_11 ] = V_20 ;
}
V_13:
if ( V_10 < 0 ) {
if ( V_9 )
F_5 ( V_9 ) ;
V_9 = NULL ;
}
( void ) V_10 ;
return V_9 ;
}
int F_6 ( struct V_1 * V_9 )
{
int V_10 = 0 ;
unsigned int V_22 = 0U ;
unsigned int V_11 = 0U ;
unsigned int V_23 = 0U ;
V_10 = F_7 ( V_9 -> V_4 ) ;
if ( V_10 < 0 )
goto V_13;
V_9 -> V_24 = true ;
V_10 = F_8 ( V_9 -> V_4 , F_9 ( 64 ) ) ;
if ( ! V_10 ) {
V_10 = F_10 ( V_9 -> V_4 , F_9 ( 64 ) ) ;
V_9 -> V_25 = 1 ;
}
if ( V_10 ) {
V_10 = F_8 ( V_9 -> V_4 , F_9 ( 32 ) ) ;
if ( ! V_10 )
V_10 = F_10 ( V_9 -> V_4 ,
F_9 ( 32 ) ) ;
V_9 -> V_25 = 0 ;
}
if ( V_10 != 0 ) {
V_10 = - V_26 ;
goto V_13;
}
V_10 = F_11 ( V_9 -> V_4 , V_27 L_1 ) ;
if ( V_10 < 0 )
goto V_13;
V_9 -> V_28 = true ;
F_12 ( V_9 -> V_4 ) ;
for ( V_22 = 0 ; V_22 < 4 ; ++ V_22 ) {
if ( V_29 & F_13 ( V_9 -> V_4 , V_22 ) ) {
T_1 V_30 ;
V_9 -> V_31 = F_14 ( V_9 -> V_4 , V_22 ) ;
if ( V_9 -> V_31 == 0U ) {
V_10 = - V_32 ;
goto V_13;
}
V_30 = F_15 ( V_9 -> V_4 , V_22 ) ;
if ( ( V_30 <= 24 ) ) {
V_10 = - V_32 ;
goto V_13;
}
V_9 -> V_33 = F_16 ( V_9 -> V_31 , V_30 ) ;
if ( ! V_9 -> V_33 ) {
V_10 = - V_32 ;
goto V_13;
}
break;
}
}
V_23 = F_17 ( ( V_34 ) V_35 , V_9 -> V_17 . V_36 ) ;
V_23 = F_17 ( V_23 , F_18 () ) ;
#if ! V_37
V_10 = F_19 ( V_9 -> V_4 , V_23 , V_23 , V_38 ) ;
if ( V_10 < 0 ) {
V_10 = F_19 ( V_9 -> V_4 , 1 , 1 ,
V_39 | V_40 ) ;
if ( V_10 < 0 )
goto V_13;
}
#endif
for ( V_11 = 0 ; V_11 < V_9 -> V_18 ; ++ V_11 ) {
if ( ! V_9 -> V_11 [ V_11 ] )
continue;
V_10 = F_20 ( V_9 -> V_11 [ V_11 ] ) ;
if ( V_10 < 0 )
goto V_13;
V_10 = F_21 ( V_9 -> V_11 [ V_11 ] ) ;
if ( V_10 < 0 )
goto V_13;
V_10 = F_22 ( V_9 -> V_11 [ V_11 ] ) ;
if ( V_10 < 0 )
goto V_13;
}
V_13:
if ( V_10 < 0 )
F_23 ( V_9 ) ;
return V_10 ;
}
int F_24 ( struct V_1 * V_9 , unsigned int V_41 ,
char * V_42 , void * V_43 , T_2 * V_44 )
{
struct V_3 * V_4 = V_9 -> V_4 ;
int V_10 = 0 ;
if ( V_4 -> V_45 || V_4 -> V_46 )
V_10 = F_25 ( F_26 ( V_4 , V_41 ) , V_47 , 0 ,
V_42 , V_43 ) ;
else
V_10 = F_25 ( F_26 ( V_4 , V_41 ) , V_48 ,
V_49 , V_42 , V_43 ) ;
if ( V_10 >= 0 ) {
V_9 -> V_50 |= ( 1 << V_41 ) ;
V_9 -> V_43 [ V_41 ] = V_43 ;
if ( V_4 -> V_45 )
F_27 ( F_26 ( V_4 , V_41 ) ,
V_44 ) ;
}
return V_10 ;
}
void F_28 ( struct V_1 * V_9 )
{
struct V_3 * V_4 = V_9 -> V_4 ;
unsigned int V_41 = 0U ;
for ( V_41 = 32U ; V_41 -- ; ) {
if ( ! ( ( 1U << V_41 ) & V_9 -> V_50 ) )
continue;
if ( V_4 -> V_45 )
F_27 ( F_26 ( V_4 , V_41 ) , NULL ) ;
F_29 ( F_26 ( V_4 , V_41 ) , V_9 -> V_43 [ V_41 ] ) ;
V_9 -> V_50 &= ~ ( 1U << V_41 ) ;
}
}
void T_3 * F_30 ( struct V_1 * V_9 )
{
return V_9 -> V_33 ;
}
unsigned int F_31 ( struct V_1 * V_9 )
{
if ( V_9 -> V_4 -> V_45 )
return V_51 ;
if ( V_9 -> V_4 -> V_46 )
return V_51 ;
return V_52 ;
}
void F_23 ( struct V_1 * V_9 )
{
if ( ! V_9 )
goto V_13;
F_28 ( V_9 ) ;
F_32 ( V_9 -> V_4 ) ;
if ( V_9 -> V_28 )
F_33 ( V_9 -> V_4 ) ;
if ( V_9 -> V_24 )
F_34 ( V_9 -> V_4 ) ;
V_13: ;
}
void F_5 ( struct V_1 * V_9 )
{
unsigned int V_11 = 0U ;
if ( ! V_9 )
goto V_13;
for ( V_11 = 0 ; V_11 < V_9 -> V_18 ; ++ V_11 ) {
if ( ! V_9 -> V_11 [ V_11 ] )
continue;
F_35 ( V_9 -> V_11 [ V_11 ] ) ;
}
if ( V_9 -> V_33 )
F_36 ( V_9 -> V_33 ) ;
F_37 ( V_9 ) ;
V_13: ;
}
int F_38 ( struct V_1 * V_9 ,
T_4 * V_53 )
{
int V_10 = 0 ;
unsigned int V_11 = 0U ;
if ( ! V_9 ) {
V_10 = - V_12 ;
goto V_13;
}
for ( V_11 = 0 ; V_11 < V_9 -> V_18 ; ++ V_11 ) {
if ( ! V_9 -> V_11 [ V_11 ] )
continue;
( void ) F_39 ( V_9 -> V_11 [ V_11 ] , V_53 ) ;
}
V_13:
return V_10 ;
}
