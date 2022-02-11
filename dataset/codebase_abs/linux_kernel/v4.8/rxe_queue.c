int F_1 ( struct V_1 * V_2 ,
struct V_3 * V_4 ,
bool V_5 ,
struct V_6 * V_7 ,
struct V_8 * V_9 ,
T_1 V_10 ,
struct V_11 * * V_12 )
{
int V_13 ;
T_2 V_14 , V_15 ;
struct V_11 * V_16 = NULL ;
if ( V_4 ) {
if ( V_5 ) {
V_14 = V_4 -> V_17 - sizeof( struct V_18 ) ;
V_15 = sizeof( struct V_18 ) ;
} else {
V_14 = V_4 -> V_17 ;
V_15 = 0 ;
}
if ( V_14 < sizeof( V_16 -> V_19 ) )
goto V_20;
V_16 = F_2 ( V_2 , V_10 , V_7 , V_9 ) ;
if ( ! V_16 )
goto V_20;
V_13 = F_3 ( V_4 -> V_21 + V_15 , & V_16 -> V_19 ,
sizeof( V_16 -> V_19 ) ) ;
if ( V_13 )
goto V_22;
F_4 ( & V_2 -> V_23 ) ;
F_5 ( & V_16 -> V_24 , & V_2 -> V_24 ) ;
F_6 ( & V_2 -> V_23 ) ;
}
* V_12 = V_16 ;
return 0 ;
V_22:
F_7 ( V_16 ) ;
V_20:
return - V_25 ;
}
struct V_26 * F_8 ( struct V_1 * V_2 ,
int * V_27 ,
unsigned int V_28 )
{
struct V_26 * V_29 ;
T_1 V_10 ;
unsigned int V_30 ;
if ( * V_27 < 0 )
goto V_20;
V_29 = F_9 ( sizeof( * V_29 ) , V_31 ) ;
if ( ! V_29 )
goto V_20;
V_29 -> V_2 = V_2 ;
V_29 -> V_28 = V_28 ;
if ( V_28 < F_10 () )
V_28 = F_10 () ;
V_28 = F_11 ( V_28 ) ;
V_29 -> V_32 = F_12 ( V_28 ) ;
V_30 = * V_27 + 1 ;
V_30 = F_11 ( V_30 ) ;
V_29 -> V_33 = V_30 - 1 ;
V_10 = sizeof( struct V_8 ) + V_30 * V_28 ;
V_29 -> V_9 = F_13 ( V_10 ) ;
if ( ! V_29 -> V_9 )
goto V_22;
V_29 -> V_9 -> V_32 = V_29 -> V_32 ;
V_29 -> V_9 -> V_33 = V_29 -> V_33 ;
V_29 -> V_10 = V_10 ;
* V_27 = V_30 - 1 ;
return V_29 ;
V_22:
F_7 ( V_29 ) ;
V_20:
return NULL ;
}
static int F_14 ( struct V_26 * V_29 , struct V_26 * V_34 ,
unsigned int V_27 )
{
if ( ! F_15 ( V_29 ) && ( V_27 < F_16 ( V_29 ) ) )
return - V_25 ;
while ( ! F_15 ( V_29 ) ) {
memcpy ( F_17 ( V_34 ) , F_18 ( V_29 ) ,
V_34 -> V_28 ) ;
F_19 ( V_34 ) ;
F_20 ( V_29 ) ;
}
F_21 ( * V_29 , * V_34 ) ;
return 0 ;
}
int F_22 ( struct V_26 * V_29 ,
unsigned int * V_35 ,
unsigned int V_28 ,
struct V_6 * V_7 ,
struct V_3 * V_4 ,
T_3 * V_36 ,
T_3 * V_37 )
{
struct V_26 * V_34 ;
unsigned int V_27 = * V_35 ;
int V_13 ;
unsigned long V_38 = 0 , V_39 ;
V_34 = F_8 ( V_29 -> V_2 , & V_27 , V_28 ) ;
if ( ! V_34 )
return - V_40 ;
V_13 = F_1 ( V_34 -> V_2 , V_4 , false , V_7 , V_34 -> V_9 ,
V_34 -> V_10 , & V_34 -> V_16 ) ;
if ( V_13 ) {
F_23 ( V_34 -> V_9 ) ;
F_7 ( V_34 ) ;
goto V_20;
}
F_24 ( V_37 , V_39 ) ;
if ( V_36 ) {
F_24 ( V_36 , V_38 ) ;
V_13 = F_14 ( V_29 , V_34 , V_27 ) ;
F_25 ( V_36 , V_38 ) ;
} else {
V_13 = F_14 ( V_29 , V_34 , V_27 ) ;
}
F_25 ( V_37 , V_39 ) ;
F_26 ( V_34 ) ;
if ( V_13 )
goto V_20;
* V_35 = V_27 ;
return 0 ;
V_20:
return V_13 ;
}
void F_26 ( struct V_26 * V_29 )
{
if ( V_29 -> V_16 )
F_27 ( & V_29 -> V_16 -> V_41 , V_42 ) ;
else
F_23 ( V_29 -> V_9 ) ;
F_7 ( V_29 ) ;
}
