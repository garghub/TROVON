void F_1 ( void )
{
unsigned long V_1 ;
F_2 ( & V_2 , V_1 ) ;
V_3 ++ ;
F_3 ( & V_2 , V_1 ) ;
}
int F_4 ( void )
{
int V_4 = 0 ;
unsigned long V_1 ;
F_2 ( & V_2 , V_1 ) ;
if ( V_3 <= 0 ) {
F_5 ( L_1 ) ;
V_4 = - V_5 ;
goto V_6;
}
V_3 -- ;
V_6:
F_3 ( & V_2 , V_1 ) ;
return V_4 ;
}
static int F_6 ( void )
{
unsigned long V_1 ;
int V_7 ;
F_2 ( & V_2 , V_1 ) ;
V_7 = V_3 ;
F_3 ( & V_2 , V_1 ) ;
return V_7 ;
}
void F_7 ( void )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 . V_10 ; V_8 ++ )
V_9 . V_11 [ V_8 ] =
V_9 . V_12 [ V_8 ] . V_13 ;
}
void F_8 ( void )
{
int V_8 ;
for ( V_8 = 0 ; V_8 < V_9 . V_10 ; V_8 ++ )
V_9 . V_14 [ V_8 ] =
V_9 . V_12 [ V_8 ] . V_13 ;
}
static int F_9 ( struct V_15 * V_16 , void * V_17 )
{
struct V_18 * V_19 = V_16 -> V_20 ;
int V_21 ;
V_21 = F_10 ( V_16 , L_2 ,
F_6 () ) ;
if ( V_21 < 0 )
F_11 ( V_19 , L_3 ) ;
return 0 ;
}
static int F_12 ( struct V_22 * V_22 ,
struct V_23 * V_23 )
{
return F_13 ( V_23 , F_9 ,
V_22 -> V_24 ) ;
}
static int F_14 ( struct V_15 * V_16 , void * V_17 )
{
struct V_18 * V_19 = V_16 -> V_20 ;
int V_21 ;
int V_8 ;
V_21 = F_15 ( V_16 , L_4 ) ;
if ( V_21 < 0 )
F_11 ( V_19 , L_5 ) ;
V_21 = F_10 ( V_16 , L_6 , L_7 ,
L_8 , L_9 ) ;
if ( V_21 < 0 )
F_11 ( V_19 , L_3 ) ;
for ( V_8 = 0 ; V_8 < V_9 . V_10 ; V_8 ++ ) {
struct V_25 * V_26 ;
V_26 = & V_9 . V_12 [ V_8 ] ;
V_21 = F_10 ( V_16 , L_10 , V_26 -> V_27 . V_28 ,
V_26 -> V_13 ? L_11 : L_12 ,
V_9 . V_11 [ V_8 ] ? L_11 : L_12 ,
V_9 . V_14 [ V_8 ] ? L_11 : L_12 ) ;
if ( V_21 < 0 )
F_11 ( V_19 , L_3 ) ;
}
return 0 ;
}
static int F_16 ( struct V_22 * V_22 , struct V_23 * V_23 )
{
return F_13 ( V_23 , F_14 ,
V_22 -> V_24 ) ;
}
int
F_17 ( struct V_29 * V_30 ,
struct V_25 * V_31 ,
int V_10 )
{
V_9 . V_32 = F_18 ( L_13 , NULL ) ;
if ( ! V_9 . V_32 )
goto V_33;
V_9 . V_34 = F_19 ( L_14 ,
V_35 , V_9 . V_32 , & V_30 -> V_19 ,
& V_36 ) ;
if ( ! V_9 . V_34 )
goto V_37;
V_9 . V_38 = F_19 ( L_15 ,
V_35 , V_9 . V_32 , & V_30 -> V_19 ,
& V_39 ) ;
if ( ! V_9 . V_38 )
goto V_40;
V_9 . V_12 = V_31 ;
V_9 . V_10 = V_10 ;
V_9 . V_11 = F_20 ( V_10 , V_41 ) ;
if ( ! V_9 . V_11 )
goto V_42;
V_9 . V_14 = F_20 ( V_10 , V_41 ) ;
if ( ! V_9 . V_14 )
goto V_43;
F_21 ( V_31 , V_10 ) ;
return 0 ;
V_43:
F_22 ( V_9 . V_11 ) ;
V_42:
F_23 ( V_9 . V_38 ) ;
V_40:
F_23 ( V_9 . V_34 ) ;
V_37:
F_23 ( V_9 . V_32 ) ;
V_33:
F_11 ( & V_30 -> V_19 , L_16 ) ;
return - V_44 ;
}
int F_24 ( void )
{
F_25 ( V_9 . V_32 ) ;
F_22 ( V_9 . V_14 ) ;
F_22 ( V_9 . V_11 ) ;
return 0 ;
}
