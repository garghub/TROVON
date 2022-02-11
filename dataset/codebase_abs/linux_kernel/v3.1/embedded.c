int F_1 ( struct V_1 * V_2 , T_1 V_3 )
{
if ( F_2 ( & V_2 -> V_4 ) ) {
F_3 ( & V_2 -> V_4 , V_3 ) ;
return 0 ;
}
if ( F_4 ( & V_2 -> V_5 ) ) {
F_5 ( & V_2 -> V_5 , V_3 ) ;
return 0 ;
}
return - V_6 ;
}
T_1 F_6 ( struct V_1 * V_2 , T_1 V_7 )
{
unsigned long V_8 ;
T_1 V_9 = 0 ;
F_7 ( & V_2 -> V_10 , V_8 ) ;
if ( F_2 ( & V_2 -> V_4 ) )
V_9 = F_8 ( & V_2 -> V_4 , V_7 ) ;
else if ( F_4 ( & V_2 -> V_5 ) )
V_9 = F_9 ( & V_2 -> V_5 , V_7 ) ;
else
F_10 ( 1 ) ;
F_11 ( & V_2 -> V_10 , V_8 ) ;
return V_9 ;
}
T_1 F_12 ( struct V_1 * V_2 , T_1 V_7 , T_1 V_11 )
{
unsigned long V_8 ;
T_1 V_9 = 0 ;
F_7 ( & V_2 -> V_10 , V_8 ) ;
if ( F_2 ( & V_2 -> V_4 ) )
V_9 = F_13 ( & V_2 -> V_4 , V_7 , V_11 ) ;
else if ( F_4 ( & V_2 -> V_5 ) )
V_9 = F_14 ( & V_2 -> V_5 , V_7 , V_11 ) ;
else
F_10 ( 1 ) ;
F_11 ( & V_2 -> V_10 , V_8 ) ;
return V_9 ;
}
T_1 F_15 ( struct V_1 * V_2 , T_1 V_7 , T_1 V_11 )
{
unsigned long V_8 ;
T_1 V_9 = 0 ;
F_7 ( & V_2 -> V_10 , V_8 ) ;
if ( F_2 ( & V_2 -> V_4 ) )
V_9 = F_16 ( & V_2 -> V_4 , V_7 , V_11 ) ;
else if ( F_4 ( & V_2 -> V_5 ) )
V_9 = F_17 ( & V_2 -> V_5 , V_7 , V_11 ) ;
else
F_10 ( 1 ) ;
F_11 ( & V_2 -> V_10 , V_8 ) ;
return V_9 ;
}
T_1 F_18 ( struct V_1 * V_2 , T_1 V_7 , T_1 V_11 )
{
unsigned long V_8 ;
T_1 V_9 = 0 ;
F_7 ( & V_2 -> V_10 , V_8 ) ;
if ( F_2 ( & V_2 -> V_4 ) )
V_9 = F_19 ( & V_2 -> V_4 , V_7 , V_11 ) ;
F_11 ( & V_2 -> V_10 , V_8 ) ;
return V_9 ;
}
T_1 F_20 ( struct V_1 * V_2 , T_1 V_7 , T_1 V_11 )
{
unsigned long V_8 ;
T_1 V_9 = 0 ;
F_7 ( & V_2 -> V_10 , V_8 ) ;
if ( F_2 ( & V_2 -> V_4 ) )
V_9 = F_21 ( & V_2 -> V_4 , V_7 , V_11 ) ;
else if ( F_4 ( & V_2 -> V_5 ) )
V_9 = F_22 ( & V_2 -> V_5 , V_7 , V_11 ) ;
else
F_10 ( 1 ) ;
F_11 ( & V_2 -> V_10 , V_8 ) ;
return V_9 ;
}
T_1 F_23 ( struct V_1 * V_2 , T_1 V_7 , T_1 V_11 )
{
unsigned long V_8 ;
T_1 V_9 = 0 ;
F_7 ( & V_2 -> V_10 , V_8 ) ;
if ( F_2 ( & V_2 -> V_4 ) )
V_9 = F_24 ( & V_2 -> V_4 , V_7 , V_11 ) ;
else if ( F_4 ( & V_2 -> V_5 ) )
V_9 = F_25 ( & V_2 -> V_5 , V_7 , V_11 ) ;
else
F_10 ( 1 ) ;
F_11 ( & V_2 -> V_10 , V_8 ) ;
return V_9 ;
}
static int F_26 ( struct V_1 * V_2 , unsigned long V_12 )
{
struct V_13 * V_14 = (struct V_13 * ) V_12 ;
struct V_15 * V_16 ;
unsigned int V_17 ;
int V_9 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_18 ; V_17 ++ ) {
V_16 = & ( V_2 -> V_19 [ V_17 ] ) ;
if ( V_16 -> V_20 . V_21 != V_22 )
continue;
if ( ! V_16 -> V_16 ||
! V_16 -> V_16 -> V_23 ||
! F_27 ( V_16 -> V_16 ) )
continue;
V_9 = F_28 ( V_16 , V_14 ) ;
if ( V_9 >= 0 )
return V_9 ;
}
return - V_6 ;
}
int F_29 ( struct V_13 * V_16 )
{
int V_24 ;
V_24 = F_30 ( V_16 ) ;
if ( ! V_24 )
return 0 ;
#ifdef F_31
V_24 = F_32 ( ( unsigned long ) V_16 , F_26 ) ;
if ( V_24 >= 0 )
return V_24 ;
#endif
return - V_6 ;
}
static int F_33 ( struct V_1 * V_2 , unsigned long V_12 )
{
const struct V_13 * V_14 = ( const struct V_13 * ) V_12 ;
struct V_15 * V_16 ;
unsigned int V_17 ;
int V_9 ;
for ( V_17 = 0 ; V_17 < V_2 -> V_18 ; V_17 ++ ) {
V_16 = & ( V_2 -> V_19 [ V_17 ] ) ;
if ( V_16 -> V_20 . V_21 != V_22 )
continue;
if ( ! V_16 -> V_16 ||
! V_16 -> V_16 -> V_23 ||
! F_27 ( V_16 -> V_16 ) )
continue;
V_9 = F_34 ( V_16 , V_14 ) ;
if ( V_9 >= 0 )
return V_9 ;
}
return - V_6 ;
}
int F_35 ( const struct V_13 * V_16 , T_2 V_25 , T_2 V_26 )
{
int V_9 ;
V_9 = F_36 ( V_16 , V_25 , V_26 ) ;
if ( V_9 >= 0 )
return V_9 ;
#ifdef F_31
V_9 = F_32 ( ( unsigned long ) V_16 , F_33 ) ;
if ( V_9 >= 0 )
return V_9 ;
#endif
return - V_6 ;
}
