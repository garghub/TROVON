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
inline void F_8 ( struct V_26 * V_27 )
{
memset ( V_27 -> V_9 -> V_28 , 0 , V_27 -> V_10 - sizeof( struct V_8 ) ) ;
}
struct V_26 * F_9 ( struct V_1 * V_2 ,
int * V_29 ,
unsigned int V_30 )
{
struct V_26 * V_27 ;
T_1 V_10 ;
unsigned int V_31 ;
if ( * V_29 < 0 )
goto V_20;
V_27 = F_10 ( sizeof( * V_27 ) , V_32 ) ;
if ( ! V_27 )
goto V_20;
V_27 -> V_2 = V_2 ;
V_27 -> V_30 = V_30 ;
if ( V_30 < F_11 () )
V_30 = F_11 () ;
V_30 = F_12 ( V_30 ) ;
V_27 -> V_33 = F_13 ( V_30 ) ;
V_31 = * V_29 + 1 ;
V_31 = F_12 ( V_31 ) ;
V_27 -> V_34 = V_31 - 1 ;
V_10 = sizeof( struct V_8 ) + V_31 * V_30 ;
V_27 -> V_9 = F_14 ( V_10 ) ;
if ( ! V_27 -> V_9 )
goto V_22;
V_27 -> V_9 -> V_33 = V_27 -> V_33 ;
V_27 -> V_9 -> V_34 = V_27 -> V_34 ;
V_27 -> V_10 = V_10 ;
* V_29 = V_31 - 1 ;
return V_27 ;
V_22:
F_7 ( V_27 ) ;
V_20:
return NULL ;
}
static int F_15 ( struct V_26 * V_27 , struct V_26 * V_35 ,
unsigned int V_29 )
{
if ( ! F_16 ( V_27 ) && ( V_29 < F_17 ( V_27 ) ) )
return - V_25 ;
while ( ! F_16 ( V_27 ) ) {
memcpy ( F_18 ( V_35 ) , F_19 ( V_27 ) ,
V_35 -> V_30 ) ;
F_20 ( V_35 ) ;
F_21 ( V_27 ) ;
}
F_22 ( * V_27 , * V_35 ) ;
return 0 ;
}
int F_23 ( struct V_26 * V_27 ,
unsigned int * V_36 ,
unsigned int V_30 ,
struct V_6 * V_7 ,
struct V_3 * V_4 ,
T_3 * V_37 ,
T_3 * V_38 )
{
struct V_26 * V_35 ;
unsigned int V_29 = * V_36 ;
int V_13 ;
unsigned long V_39 = 0 , V_40 ;
V_35 = F_9 ( V_27 -> V_2 , & V_29 , V_30 ) ;
if ( ! V_35 )
return - V_41 ;
V_13 = F_1 ( V_35 -> V_2 , V_4 , false , V_7 , V_35 -> V_9 ,
V_35 -> V_10 , & V_35 -> V_16 ) ;
if ( V_13 ) {
F_24 ( V_35 -> V_9 ) ;
F_7 ( V_35 ) ;
goto V_20;
}
F_25 ( V_38 , V_40 ) ;
if ( V_37 ) {
F_25 ( V_37 , V_39 ) ;
V_13 = F_15 ( V_27 , V_35 , V_29 ) ;
F_26 ( V_37 , V_39 ) ;
} else {
V_13 = F_15 ( V_27 , V_35 , V_29 ) ;
}
F_26 ( V_38 , V_40 ) ;
F_27 ( V_35 ) ;
if ( V_13 )
goto V_20;
* V_36 = V_29 ;
return 0 ;
V_20:
return V_13 ;
}
void F_27 ( struct V_26 * V_27 )
{
if ( V_27 -> V_16 )
F_28 ( & V_27 -> V_16 -> V_42 , V_43 ) ;
else
F_24 ( V_27 -> V_9 ) ;
F_7 ( V_27 ) ;
}
