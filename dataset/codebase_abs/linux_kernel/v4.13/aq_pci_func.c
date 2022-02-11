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
V_10 = F_7 ( V_9 -> V_4 ) ;
if ( V_10 < 0 )
goto V_13;
V_9 -> V_23 = true ;
V_10 = F_8 ( V_9 -> V_4 , F_9 ( 64 ) ) ;
if ( ! V_10 ) {
V_10 = F_10 ( V_9 -> V_4 , F_9 ( 64 ) ) ;
V_9 -> V_24 = 1 ;
}
if ( V_10 ) {
V_10 = F_8 ( V_9 -> V_4 , F_9 ( 32 ) ) ;
if ( ! V_10 )
V_10 = F_10 ( V_9 -> V_4 ,
F_9 ( 32 ) ) ;
V_9 -> V_24 = 0 ;
}
if ( V_10 != 0 ) {
V_10 = - V_25 ;
goto V_13;
}
V_10 = F_11 ( V_9 -> V_4 , V_26 L_1 ) ;
if ( V_10 < 0 )
goto V_13;
V_9 -> V_27 = true ;
F_12 ( V_9 -> V_4 ) ;
for ( V_22 = 0 ; V_22 < 4 ; ++ V_22 ) {
if ( V_28 & F_13 ( V_9 -> V_4 , V_22 ) ) {
T_1 V_29 ;
V_9 -> V_30 = F_14 ( V_9 -> V_4 , V_22 ) ;
if ( V_9 -> V_30 == 0U ) {
V_10 = - V_31 ;
goto V_13;
}
V_29 = F_15 ( V_9 -> V_4 , V_22 ) ;
if ( ( V_29 <= 24 ) ) {
V_10 = - V_31 ;
goto V_13;
}
V_9 -> V_32 = F_16 ( V_9 -> V_30 , V_29 ) ;
if ( ! V_9 -> V_32 ) {
V_10 = - V_31 ;
goto V_13;
}
break;
}
}
#if ! V_33
V_10 = F_17 ( V_9 -> V_4 , V_9 -> V_17 . V_34 ,
V_9 -> V_17 . V_34 , V_35 ) ;
if ( V_10 < 0 ) {
V_10 = F_17 ( V_9 -> V_4 , 1 , 1 ,
V_36 | V_37 ) ;
if ( V_10 < 0 )
goto V_13;
}
#endif
for ( V_11 = 0 ; V_11 < V_9 -> V_18 ; ++ V_11 ) {
if ( ! V_9 -> V_11 [ V_11 ] )
continue;
V_10 = F_18 ( V_9 -> V_11 [ V_11 ] ) ;
if ( V_10 < 0 )
goto V_13;
V_10 = F_19 ( V_9 -> V_11 [ V_11 ] ) ;
if ( V_10 < 0 )
goto V_13;
V_10 = F_20 ( V_9 -> V_11 [ V_11 ] ) ;
if ( V_10 < 0 )
goto V_13;
}
V_13:
if ( V_10 < 0 )
F_21 ( V_9 ) ;
return V_10 ;
}
int F_22 ( struct V_1 * V_9 , unsigned int V_38 ,
char * V_39 , void * V_40 , T_2 * V_41 )
{
struct V_3 * V_4 = V_9 -> V_4 ;
int V_10 = 0 ;
if ( V_4 -> V_42 || V_4 -> V_43 )
V_10 = F_23 ( F_24 ( V_4 , V_38 ) , V_44 , 0 ,
V_39 , V_40 ) ;
else
V_10 = F_23 ( F_24 ( V_4 , V_38 ) , V_45 ,
V_46 , V_39 , V_40 ) ;
if ( V_10 >= 0 ) {
V_9 -> V_47 |= ( 1 << V_38 ) ;
V_9 -> V_40 [ V_38 ] = V_40 ;
if ( V_4 -> V_42 )
F_25 ( F_24 ( V_4 , V_38 ) ,
V_41 ) ;
}
return V_10 ;
}
void F_26 ( struct V_1 * V_9 )
{
struct V_3 * V_4 = V_9 -> V_4 ;
unsigned int V_38 = 0U ;
for ( V_38 = 32U ; V_38 -- ; ) {
if ( ! ( ( 1U << V_38 ) & V_9 -> V_47 ) )
continue;
if ( V_4 -> V_42 )
F_25 ( F_24 ( V_4 , V_38 ) , NULL ) ;
F_27 ( F_24 ( V_4 , V_38 ) , V_9 -> V_40 [ V_38 ] ) ;
V_9 -> V_47 &= ~ ( 1U << V_38 ) ;
}
}
void T_3 * F_28 ( struct V_1 * V_9 )
{
return V_9 -> V_32 ;
}
unsigned int F_29 ( struct V_1 * V_9 )
{
if ( V_9 -> V_4 -> V_42 )
return V_48 ;
if ( V_9 -> V_4 -> V_43 )
return V_48 ;
return V_49 ;
}
void F_21 ( struct V_1 * V_9 )
{
if ( ! V_9 )
goto V_13;
F_26 ( V_9 ) ;
F_30 ( V_9 -> V_4 ) ;
if ( V_9 -> V_27 )
F_31 ( V_9 -> V_4 ) ;
if ( V_9 -> V_23 )
F_32 ( V_9 -> V_4 ) ;
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
F_33 ( V_9 -> V_11 [ V_11 ] ) ;
}
F_34 ( V_9 ) ;
V_13: ;
}
int F_35 ( struct V_1 * V_9 ,
T_4 * V_50 )
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
( void ) F_36 ( V_9 -> V_11 [ V_11 ] , V_50 ) ;
}
V_13:
return V_10 ;
}
