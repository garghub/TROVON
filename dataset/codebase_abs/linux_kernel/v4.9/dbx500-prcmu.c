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
static int F_7 ( struct V_8 * V_9 , void * V_10 )
{
F_8 ( V_9 , L_2 ,
F_6 () ) ;
return 0 ;
}
static int F_9 ( struct V_11 * V_11 ,
struct V_12 * V_12 )
{
return F_10 ( V_12 , F_7 ,
V_11 -> V_13 ) ;
}
static int F_11 ( struct V_8 * V_9 , void * V_10 )
{
int V_14 ;
F_12 ( V_9 , L_3 ) ;
F_8 ( V_9 , L_4 , L_5 , L_6 , L_7 ) ;
for ( V_14 = 0 ; V_14 < V_15 . V_16 ; V_14 ++ ) {
struct V_17 * V_18 ;
V_18 = & V_15 . V_19 [ V_14 ] ;
F_8 ( V_9 , L_8 ,
V_18 -> V_20 . V_21 ,
V_18 -> V_22 ? L_9 : L_10 ,
V_15 . V_23 [ V_14 ] ? L_9 : L_10 ,
V_15 . V_24 [ V_14 ] ? L_9 : L_10 ) ;
}
return 0 ;
}
static int F_13 ( struct V_11 * V_11 , struct V_12 * V_12 )
{
return F_10 ( V_12 , F_11 ,
V_11 -> V_13 ) ;
}
int
F_14 ( struct V_25 * V_26 ,
struct V_17 * V_27 ,
int V_16 )
{
V_15 . V_28 = F_15 ( L_11 , NULL ) ;
if ( ! V_15 . V_28 )
goto V_29;
V_15 . V_30 = F_16 ( L_12 ,
V_31 , V_15 . V_28 , & V_26 -> V_32 ,
& V_33 ) ;
if ( ! V_15 . V_30 )
goto V_34;
V_15 . V_35 = F_16 ( L_13 ,
V_31 , V_15 . V_28 , & V_26 -> V_32 ,
& V_36 ) ;
if ( ! V_15 . V_35 )
goto V_37;
V_15 . V_19 = V_27 ;
V_15 . V_16 = V_16 ;
V_15 . V_23 = F_17 ( V_16 , V_38 ) ;
if ( ! V_15 . V_23 )
goto V_39;
V_15 . V_24 = F_17 ( V_16 , V_38 ) ;
if ( ! V_15 . V_24 )
goto V_40;
F_18 ( V_27 , V_16 ) ;
return 0 ;
V_40:
F_19 ( V_15 . V_23 ) ;
V_39:
F_20 ( V_15 . V_35 ) ;
V_37:
F_20 ( V_15 . V_30 ) ;
V_34:
F_20 ( V_15 . V_28 ) ;
V_29:
F_21 ( & V_26 -> V_32 , L_14 ) ;
return - V_41 ;
}
int F_22 ( void )
{
F_23 ( V_15 . V_28 ) ;
F_19 ( V_15 . V_24 ) ;
F_19 ( V_15 . V_23 ) ;
return 0 ;
}
