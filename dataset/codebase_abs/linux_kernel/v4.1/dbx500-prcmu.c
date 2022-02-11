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
F_10 ( V_16 , L_2 ,
F_6 () ) ;
return 0 ;
}
static int F_11 ( struct V_18 * V_18 ,
struct V_19 * V_19 )
{
return F_12 ( V_19 , F_9 ,
V_18 -> V_20 ) ;
}
static int F_13 ( struct V_15 * V_16 , void * V_17 )
{
int V_8 ;
F_14 ( V_16 , L_3 ) ;
F_10 ( V_16 , L_4 , L_5 , L_6 , L_7 ) ;
for ( V_8 = 0 ; V_8 < V_9 . V_10 ; V_8 ++ ) {
struct V_21 * V_22 ;
V_22 = & V_9 . V_12 [ V_8 ] ;
F_10 ( V_16 , L_8 ,
V_22 -> V_23 . V_24 ,
V_22 -> V_13 ? L_9 : L_10 ,
V_9 . V_11 [ V_8 ] ? L_9 : L_10 ,
V_9 . V_14 [ V_8 ] ? L_9 : L_10 ) ;
}
return 0 ;
}
static int F_15 ( struct V_18 * V_18 , struct V_19 * V_19 )
{
return F_12 ( V_19 , F_13 ,
V_18 -> V_20 ) ;
}
int
F_16 ( struct V_25 * V_26 ,
struct V_21 * V_27 ,
int V_10 )
{
V_9 . V_28 = F_17 ( L_11 , NULL ) ;
if ( ! V_9 . V_28 )
goto V_29;
V_9 . V_30 = F_18 ( L_12 ,
V_31 , V_9 . V_28 , & V_26 -> V_32 ,
& V_33 ) ;
if ( ! V_9 . V_30 )
goto V_34;
V_9 . V_35 = F_18 ( L_13 ,
V_31 , V_9 . V_28 , & V_26 -> V_32 ,
& V_36 ) ;
if ( ! V_9 . V_35 )
goto V_37;
V_9 . V_12 = V_27 ;
V_9 . V_10 = V_10 ;
V_9 . V_11 = F_19 ( V_10 , V_38 ) ;
if ( ! V_9 . V_11 )
goto V_39;
V_9 . V_14 = F_19 ( V_10 , V_38 ) ;
if ( ! V_9 . V_14 )
goto V_40;
F_20 ( V_27 , V_10 ) ;
return 0 ;
V_40:
F_21 ( V_9 . V_11 ) ;
V_39:
F_22 ( V_9 . V_35 ) ;
V_37:
F_22 ( V_9 . V_30 ) ;
V_34:
F_22 ( V_9 . V_28 ) ;
V_29:
F_23 ( & V_26 -> V_32 , L_14 ) ;
return - V_41 ;
}
int F_24 ( void )
{
F_25 ( V_9 . V_28 ) ;
F_21 ( V_9 . V_14 ) ;
F_21 ( V_9 . V_11 ) ;
return 0 ;
}
