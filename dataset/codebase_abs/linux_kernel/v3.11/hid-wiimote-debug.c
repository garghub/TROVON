static T_1 F_1 ( struct V_1 * V_2 , char T_2 * V_3 , T_3 V_4 ,
T_4 * V_5 )
{
struct V_6 * V_7 = V_2 -> V_8 ;
struct V_9 * V_10 = V_7 -> V_10 ;
unsigned long V_11 ;
T_1 V_12 ;
char V_13 [ 16 ] ;
T_5 V_14 = 0 ;
if ( V_4 == 0 )
return - V_15 ;
if ( * V_5 > 0xffffff )
return 0 ;
if ( V_4 > 16 )
V_4 = 16 ;
V_12 = F_2 ( V_10 ) ;
if ( V_12 )
return V_12 ;
F_3 ( & V_10 -> V_16 . V_17 , V_11 ) ;
V_10 -> V_16 . V_18 = V_4 ;
V_10 -> V_16 . V_19 = V_13 ;
F_4 ( V_10 , V_20 , * V_5 & 0xffff ) ;
F_5 ( V_10 , * V_5 , V_4 ) ;
F_6 ( & V_10 -> V_16 . V_17 , V_11 ) ;
V_12 = F_7 ( V_10 ) ;
if ( ! V_12 )
V_14 = V_10 -> V_16 . V_18 ;
F_3 ( & V_10 -> V_16 . V_17 , V_11 ) ;
V_10 -> V_16 . V_19 = NULL ;
F_6 ( & V_10 -> V_16 . V_17 , V_11 ) ;
F_8 ( V_10 ) ;
if ( V_12 )
return V_12 ;
else if ( V_14 == 0 )
return - V_21 ;
if ( F_9 ( V_3 , V_13 , V_14 ) )
return - V_22 ;
* V_5 += V_14 ;
V_12 = V_14 ;
return V_12 ;
}
static int F_10 ( struct V_23 * V_2 , void * V_24 )
{
struct V_6 * V_7 = V_2 -> V_25 ;
const char * V_26 = NULL ;
unsigned long V_11 ;
T_6 V_27 ;
F_3 ( & V_7 -> V_10 -> V_16 . V_17 , V_11 ) ;
V_27 = V_7 -> V_10 -> V_16 . V_27 ;
F_6 ( & V_7 -> V_10 -> V_16 . V_17 , V_11 ) ;
if ( V_27 < V_28 )
V_26 = V_29 [ V_27 ] ;
if ( ! V_26 )
V_26 = L_1 ;
F_11 ( V_2 , L_2 , V_26 ) ;
return 0 ;
}
static int F_12 ( struct V_30 * V_31 , struct V_1 * V_2 )
{
return F_13 ( V_2 , F_10 , V_31 -> V_32 ) ;
}
static T_1 F_14 ( struct V_1 * V_2 , const char T_2 * V_3 ,
T_3 V_4 , T_4 * V_5 )
{
struct V_23 * V_33 = V_2 -> V_8 ;
struct V_6 * V_7 = V_33 -> V_25 ;
unsigned long V_11 ;
char V_13 [ 16 ] ;
T_1 V_34 ;
int V_31 ;
if ( V_4 == 0 )
return - V_15 ;
V_34 = F_15 ( ( T_3 ) 15 , V_4 ) ;
if ( F_16 ( V_13 , V_3 , V_34 ) )
return - V_22 ;
V_13 [ V_34 ] = 0 ;
for ( V_31 = 0 ; V_31 < V_28 ; ++ V_31 ) {
if ( ! V_29 [ V_31 ] )
continue;
if ( ! strcasecmp ( V_13 , V_29 [ V_31 ] ) )
break;
}
if ( V_31 == V_28 )
V_31 = F_17 ( V_13 , NULL , 16 ) ;
F_3 ( & V_7 -> V_10 -> V_16 . V_17 , V_11 ) ;
V_7 -> V_10 -> V_16 . V_11 &= ~ V_35 ;
F_18 ( V_7 -> V_10 , ( T_6 ) V_31 ) ;
if ( V_31 != V_36 )
V_7 -> V_10 -> V_16 . V_11 |= V_35 ;
F_6 ( & V_7 -> V_10 -> V_16 . V_17 , V_11 ) ;
return V_34 ;
}
int F_19 ( struct V_9 * V_10 )
{
struct V_6 * V_7 ;
unsigned long V_11 ;
int V_12 = - V_37 ;
V_7 = F_20 ( sizeof( * V_7 ) , V_38 ) ;
if ( ! V_7 )
return - V_37 ;
V_7 -> V_10 = V_10 ;
V_7 -> V_39 = F_21 ( L_3 , V_40 ,
V_7 -> V_10 -> V_41 -> V_42 , V_7 , & V_43 ) ;
if ( ! V_7 -> V_39 )
goto V_44;
V_7 -> V_27 = F_21 ( L_4 , V_40 ,
V_7 -> V_10 -> V_41 -> V_42 , V_7 , & V_45 ) ;
if ( ! V_7 -> V_27 )
goto V_46;
F_3 ( & V_10 -> V_16 . V_17 , V_11 ) ;
V_10 -> V_47 = V_7 ;
F_6 ( & V_10 -> V_16 . V_17 , V_11 ) ;
return 0 ;
V_46:
F_22 ( V_7 -> V_39 ) ;
V_44:
F_23 ( V_7 ) ;
return V_12 ;
}
void F_24 ( struct V_9 * V_10 )
{
struct V_6 * V_7 = V_10 -> V_47 ;
unsigned long V_11 ;
if ( ! V_7 )
return;
F_3 ( & V_10 -> V_16 . V_17 , V_11 ) ;
V_10 -> V_47 = NULL ;
F_6 ( & V_10 -> V_16 . V_17 , V_11 ) ;
F_22 ( V_7 -> V_27 ) ;
F_22 ( V_7 -> V_39 ) ;
F_23 ( V_7 ) ;
}
