static void F_1 ( void * V_1 )
{
if ( V_2 -> V_3 == V_1 )
F_2 ( & V_2 -> V_3 -> V_4 ) ;
}
static int F_3 ( T_1 * V_5 , int V_6 , int V_7 )
{
void * V_8 , * V_9 ;
int V_10 ;
if ( V_6 <= V_5 -> V_11 )
return 0 ;
V_10 = V_5 -> V_11 ;
V_6 = ( V_6 + ( V_12 / V_13 - 1 ) ) &
( ~ ( V_12 / V_13 - 1 ) ) ;
if ( V_6 * V_13 > V_12 )
V_9 = F_4 ( V_6 * V_13 ) ;
else
V_9 = ( void * ) F_5 ( V_14 ) ;
if ( ! V_9 )
return - V_15 ;
if ( V_10 )
memcpy ( V_9 , V_5 -> V_16 , V_10 * V_13 ) ;
V_8 = V_5 -> V_16 ;
memset ( V_9 + V_10 * V_13 , 0 ,
( V_6 - V_10 ) * V_13 ) ;
F_6 ( V_9 , V_6 ) ;
#ifdef F_7
F_8 () ;
#endif
V_5 -> V_16 = V_9 ;
F_8 () ;
V_5 -> V_11 = V_6 ;
F_8 () ;
if ( V_7 ) {
#ifdef F_9
F_10 () ;
F_2 ( V_5 ) ;
if ( ! F_11 ( F_12 ( V_2 -> V_17 ) ,
F_13 ( F_14 () ) ) )
F_15 ( F_1 , V_2 -> V_17 , 1 ) ;
F_16 () ;
#else
F_2 ( V_5 ) ;
#endif
}
if ( V_10 ) {
F_17 ( V_8 , V_10 ) ;
if ( V_10 * V_13 > V_12 )
F_18 ( V_8 ) ;
else
F_19 ( F_20 ( V_8 ) ) ;
}
return 0 ;
}
static inline int F_21 ( T_1 * V_18 , T_1 * V_19 )
{
int V_20 = F_3 ( V_18 , V_19 -> V_11 , 0 ) ;
int V_21 ;
if ( V_20 < 0 )
return V_20 ;
for ( V_21 = 0 ; V_21 < V_19 -> V_11 ; V_21 ++ )
F_22 ( V_18 -> V_16 , V_21 , V_19 -> V_16 + V_21 * V_13 ) ;
return 0 ;
}
int F_23 ( struct V_22 * V_23 , struct V_24 * V_17 )
{
struct V_24 * V_25 ;
int V_26 = 0 ;
F_24 ( & V_17 -> V_4 . V_27 ) ;
V_17 -> V_4 . V_11 = 0 ;
V_25 = V_2 -> V_17 ;
if ( V_25 && V_25 -> V_4 . V_11 > 0 ) {
F_25 ( & V_25 -> V_4 . V_27 ) ;
V_26 = F_21 ( & V_17 -> V_4 , & V_25 -> V_4 ) ;
F_26 ( & V_25 -> V_4 . V_27 ) ;
}
return V_26 ;
}
void F_27 ( struct V_24 * V_17 )
{
if ( V_17 -> V_4 . V_11 ) {
#ifdef F_28
if ( V_17 == V_2 -> V_3 )
F_29 () ;
#endif
F_17 ( V_17 -> V_4 . V_16 , V_17 -> V_4 . V_11 ) ;
if ( V_17 -> V_4 . V_11 * V_13 > V_12 )
F_18 ( V_17 -> V_4 . V_16 ) ;
else
F_19 ( F_20 ( V_17 -> V_4 . V_16 ) ) ;
V_17 -> V_4 . V_11 = 0 ;
}
}
static int F_30 ( void T_2 * V_28 , unsigned long V_29 )
{
int V_20 ;
unsigned long V_11 ;
struct V_24 * V_17 = V_2 -> V_17 ;
if ( ! V_17 -> V_4 . V_11 )
return 0 ;
if ( V_29 > V_13 * V_30 )
V_29 = V_13 * V_30 ;
F_25 ( & V_17 -> V_4 . V_27 ) ;
V_11 = V_17 -> V_4 . V_11 * V_13 ;
if ( V_11 > V_29 )
V_11 = V_29 ;
V_20 = 0 ;
if ( F_31 ( V_28 , V_17 -> V_4 . V_16 , V_11 ) )
V_20 = - V_31 ;
F_26 ( & V_17 -> V_4 . V_27 ) ;
if ( V_20 < 0 )
goto V_32;
if ( V_11 != V_29 ) {
if ( F_32 ( V_28 + V_11 , V_29 - V_11 ) != 0 ) {
V_20 = - V_31 ;
goto V_32;
}
}
return V_29 ;
V_32:
return V_20 ;
}
static int F_33 ( void T_2 * V_28 , unsigned long V_29 )
{
#ifdef F_28
unsigned long V_11 = 5 * sizeof( struct V_33 ) ;
#else
unsigned long V_11 = 128 ;
#endif
if ( V_29 > V_11 )
V_29 = V_11 ;
if ( F_32 ( V_28 , V_29 ) )
return - V_31 ;
return V_29 ;
}
static int F_34 ( void T_2 * V_28 , unsigned long V_29 , int V_34 )
{
struct V_24 * V_17 = V_2 -> V_17 ;
struct V_33 V_16 ;
int error ;
struct V_35 V_36 ;
error = - V_37 ;
if ( V_29 != sizeof( V_36 ) )
goto V_38;
error = - V_31 ;
if ( F_35 ( & V_36 , V_28 , sizeof( V_36 ) ) )
goto V_38;
error = - V_37 ;
if ( V_36 . V_39 >= V_30 )
goto V_38;
if ( V_36 . V_40 == 3 ) {
if ( V_34 )
goto V_38;
if ( V_36 . V_41 == 0 )
goto V_38;
}
F_25 ( & V_17 -> V_4 . V_27 ) ;
if ( V_36 . V_39 >= V_17 -> V_4 . V_11 ) {
error = F_3 ( & V_2 -> V_17 -> V_4 ,
V_36 . V_39 + 1 , 1 ) ;
if ( error < 0 )
goto V_42;
}
if ( V_36 . V_43 == 0 && V_36 . V_44 == 0 ) {
if ( V_34 || F_36 ( & V_36 ) ) {
memset ( & V_16 , 0 , sizeof( V_16 ) ) ;
goto V_45;
}
}
F_37 ( & V_16 , & V_36 ) ;
if ( V_34 )
V_16 . V_46 = 0 ;
V_45:
F_22 ( V_17 -> V_4 . V_16 , V_36 . V_39 , & V_16 ) ;
error = 0 ;
V_42:
F_26 ( & V_17 -> V_4 . V_27 ) ;
V_38:
return error ;
}
T_3 int F_38 ( int V_47 , void T_2 * V_28 ,
unsigned long V_29 )
{
int V_48 = - V_49 ;
switch ( V_47 ) {
case 0 :
V_48 = F_30 ( V_28 , V_29 ) ;
break;
case 1 :
V_48 = F_34 ( V_28 , V_29 , 1 ) ;
break;
case 2 :
V_48 = F_33 ( V_28 , V_29 ) ;
break;
case 0x11 :
V_48 = F_34 ( V_28 , V_29 , 0 ) ;
break;
}
return V_48 ;
}
