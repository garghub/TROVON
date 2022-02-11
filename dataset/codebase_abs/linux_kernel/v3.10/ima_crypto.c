int F_1 ( void )
{
long V_1 ;
V_2 = F_2 ( V_3 , 0 , 0 ) ;
if ( F_3 ( V_2 ) ) {
V_1 = F_4 ( V_2 ) ;
F_5 ( L_1 , V_3 , V_1 ) ;
return V_1 ;
}
return 0 ;
}
int F_6 ( struct V_4 * V_4 , char * V_5 )
{
T_1 V_6 , V_7 = 0 ;
char * V_8 ;
int V_1 , V_9 = 0 ;
struct {
struct V_10 V_11 ;
char V_12 [ F_7 ( V_2 ) ] ;
} V_13 ;
V_13 . V_11 . V_14 = V_2 ;
V_13 . V_11 . V_15 = 0 ;
V_1 = F_8 ( & V_13 . V_11 ) ;
if ( V_1 != 0 )
return V_1 ;
V_8 = F_9 ( V_16 , V_17 ) ;
if ( ! V_8 ) {
V_1 = - V_18 ;
goto V_19;
}
if ( ! ( V_4 -> V_20 & V_21 ) ) {
V_4 -> V_20 |= V_21 ;
V_9 = 1 ;
}
V_6 = F_10 ( F_11 ( V_4 ) ) ;
while ( V_7 < V_6 ) {
int V_22 ;
V_22 = F_12 ( V_4 , V_7 , V_8 , V_16 ) ;
if ( V_22 < 0 ) {
V_1 = V_22 ;
break;
}
if ( V_22 == 0 )
break;
V_7 += V_22 ;
V_1 = F_13 ( & V_13 . V_11 , V_8 , V_22 ) ;
if ( V_1 )
break;
}
F_14 ( V_8 ) ;
if ( ! V_1 )
V_1 = F_15 ( & V_13 . V_11 , V_5 ) ;
if ( V_9 )
V_4 -> V_20 &= ~ V_21 ;
V_19:
return V_1 ;
}
int F_16 ( const void * V_23 , int V_24 , char * V_5 )
{
struct {
struct V_10 V_11 ;
char V_12 [ F_7 ( V_2 ) ] ;
} V_13 ;
V_13 . V_11 . V_14 = V_2 ;
V_13 . V_11 . V_15 = 0 ;
return F_17 ( & V_13 . V_11 , V_23 , V_24 , V_5 ) ;
}
static void T_2 F_18 ( int V_25 , T_3 * V_26 )
{
if ( ! V_27 )
return;
if ( F_19 ( V_28 , V_25 , V_26 ) != 0 )
F_5 ( L_2 ) ;
}
int T_2 F_20 ( char * V_5 )
{
T_3 V_29 [ V_30 ] ;
int V_1 , V_31 ;
struct {
struct V_10 V_11 ;
char V_12 [ F_7 ( V_2 ) ] ;
} V_13 ;
V_13 . V_11 . V_14 = V_2 ;
V_13 . V_11 . V_15 = 0 ;
V_1 = F_8 ( & V_13 . V_11 ) ;
if ( V_1 != 0 )
return V_1 ;
for ( V_31 = V_32 ; V_31 < V_33 ; V_31 ++ ) {
F_18 ( V_31 , V_29 ) ;
V_1 = F_13 ( & V_13 . V_11 , V_29 , V_30 ) ;
}
if ( ! V_1 )
F_15 ( & V_13 . V_11 , V_5 ) ;
return V_1 ;
}
