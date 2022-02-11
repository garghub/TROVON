int F_1 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 -> V_5 -> V_6 . V_7 ;
int V_8 ;
struct V_9 * V_10 ;
int V_11 = 0 ;
unsigned long V_12 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_13 ; ++ V_8 ) {
V_10 = F_2 ( V_2 ) ;
if ( ! V_10 ) {
V_11 = - V_14 ;
goto V_15;
}
V_11 = F_3 ( V_10 , V_3 ) ;
if ( V_11 )
goto V_15;
F_4 ( & V_2 -> V_16 , V_12 ) ;
F_5 ( & V_10 -> V_17 , & V_2 -> V_18 . V_17 ) ;
F_6 ( & V_2 -> V_16 , V_12 ) ;
}
return 0 ;
V_15:
F_7 ( & V_2 -> V_4 -> V_19 , L_1 ) ;
F_8 ( V_2 ) ;
return V_11 ;
}
int F_9 ( struct V_1 * V_2 )
{
T_1 V_3 = V_2 -> V_4 -> V_5 -> V_6 . V_7 ;
int V_8 ;
unsigned long V_12 ;
for ( V_8 = 0 ; V_8 < V_2 -> V_20 ; ++ V_8 ) {
struct V_21 * V_22 ;
V_22 = F_10 ( sizeof( struct V_21 ) , V_23 ) ;
if ( ! V_22 )
goto V_15;
V_22 -> V_24 . V_25 = F_11 ( V_3 , V_23 ) ;
if ( ! V_22 -> V_24 . V_25 ) {
F_12 ( V_22 ) ;
goto V_15;
}
F_4 ( & V_2 -> V_26 , V_12 ) ;
F_5 ( & V_22 -> V_17 , & V_2 -> V_27 . V_17 ) ;
F_6 ( & V_2 -> V_26 , V_12 ) ;
}
return 0 ;
V_15:
F_7 ( & V_2 -> V_4 -> V_19 , L_2 ) ;
F_8 ( V_2 ) ;
return - V_14 ;
}
void F_8 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
unsigned long V_12 ;
F_4 ( & V_2 -> V_16 , V_12 ) ;
while ( ! F_13 ( & V_2 -> V_18 . V_17 ) ) {
V_10 = F_14 ( V_2 -> V_18 . V_17 . V_28 , struct V_9 ,
V_17 ) ;
F_15 ( & V_10 -> V_17 ) ;
F_12 ( V_10 -> V_29 . V_25 ) ;
F_12 ( V_10 ) ;
}
F_6 ( & V_2 -> V_16 , V_12 ) ;
F_4 ( & V_2 -> V_30 , V_12 ) ;
while ( ! F_13 ( & V_2 -> V_31 . V_17 ) ) {
V_10 = F_14 ( V_2 -> V_31 . V_17 . V_28 ,
struct V_9 , V_17 ) ;
F_15 ( & V_10 -> V_17 ) ;
F_12 ( V_10 -> V_29 . V_25 ) ;
F_12 ( V_10 ) ;
}
F_6 ( & V_2 -> V_30 , V_12 ) ;
}
void F_16 ( struct V_1 * V_2 )
{
struct V_21 * V_22 ;
unsigned long V_12 ;
F_4 ( & V_2 -> V_26 , V_12 ) ;
while ( ! F_13 ( & V_2 -> V_27 . V_17 ) ) {
V_22 = F_14 ( V_2 -> V_27 . V_17 . V_28 ,
struct V_21 , V_17 ) ;
F_15 ( & V_22 -> V_17 ) ;
F_12 ( V_22 -> V_24 . V_25 ) ;
F_12 ( V_22 ) ;
}
F_6 ( & V_2 -> V_26 , V_12 ) ;
F_4 ( & V_2 -> V_32 , V_12 ) ;
while ( ! F_13 ( & V_2 -> V_33 . V_17 ) ) {
V_22 = F_14 ( V_2 -> V_33 . V_17 . V_28 ,
struct V_21 , V_17 ) ;
F_15 ( & V_22 -> V_17 ) ;
F_12 ( V_22 -> V_24 . V_25 ) ;
F_12 ( V_22 ) ;
}
F_6 ( & V_2 -> V_32 , V_12 ) ;
}
void F_17 ( struct V_9 * V_10 )
{
if ( V_10 == NULL )
return;
F_12 ( V_10 -> V_29 . V_25 ) ;
F_12 ( V_10 ) ;
}
struct V_9 * F_2 ( struct V_1 * V_2 )
{
struct V_9 * V_10 ;
V_10 = F_10 ( sizeof( struct V_9 ) , V_23 ) ;
if ( ! V_10 )
return NULL ;
F_18 ( & V_10 -> V_17 ) ;
V_10 -> V_2 = V_2 ;
V_10 -> V_34 = 0 ;
return V_10 ;
}
int F_3 ( struct V_9 * V_10 , T_1 V_35 )
{
if ( ! V_10 )
return - V_36 ;
if ( V_35 == 0 )
return 0 ;
V_10 -> V_29 . V_25 = F_11 ( V_35 , V_23 ) ;
if ( ! V_10 -> V_29 . V_25 )
return - V_14 ;
V_10 -> V_29 . V_37 = V_35 ;
return 0 ;
}
int F_19 ( struct V_9 * V_10 )
{
struct V_1 * V_2 ;
int V_38 = 0 ;
unsigned long V_12 ;
if ( ! V_10 || ! V_10 -> V_2 )
return - V_39 ;
V_2 = V_10 -> V_2 ;
F_4 ( & V_2 -> V_16 , V_12 ) ;
F_5 ( & V_10 -> V_17 , & V_2 -> V_18 . V_17 ) ;
F_6 ( & V_2 -> V_16 , V_12 ) ;
if ( ! V_2 -> V_40 )
V_38 = F_20 ( V_2 ) ;
return V_38 ;
}
