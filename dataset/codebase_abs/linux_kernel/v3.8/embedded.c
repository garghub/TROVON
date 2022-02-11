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
int F_6 ( struct V_1 * V_2 )
{
struct V_7 V_8 = {} ;
struct V_9 * V_10 ;
if ( F_2 ( & V_2 -> V_4 ) ) {
V_8 . V_11 = & V_2 -> V_4 ;
V_8 . V_12 = V_13 ;
V_8 . V_14 = V_15 ;
V_8 . V_16 = V_2 -> V_4 . V_16 ;
} else if ( F_4 ( & V_2 -> V_5 ) ) {
V_8 . V_11 = & V_2 -> V_5 ;
V_8 . V_12 = V_17 ;
V_8 . V_14 = V_18 ;
V_8 . V_16 = V_19 ;
} else {
return - V_6 ;
}
V_10 = F_7 ( NULL , L_1 ,
V_2 -> V_20 , & V_8 ,
sizeof( V_8 ) ) ;
if ( F_8 ( V_10 ) ) {
F_9 (KERN_INFO PFX
L_2 ,
PTR_ERR(pdev)) ;
return F_10 ( V_10 ) ;
}
V_2 -> V_21 = V_10 ;
return 0 ;
}
T_1 F_11 ( struct V_1 * V_2 , T_1 V_22 )
{
unsigned long V_23 ;
T_1 V_24 = 0 ;
F_12 ( & V_2 -> V_25 , V_23 ) ;
if ( F_2 ( & V_2 -> V_4 ) )
V_24 = F_13 ( & V_2 -> V_4 , V_22 ) ;
else if ( F_4 ( & V_2 -> V_5 ) )
V_24 = F_14 ( & V_2 -> V_5 , V_22 ) ;
else
F_15 ( 1 ) ;
F_16 ( & V_2 -> V_25 , V_23 ) ;
return V_24 ;
}
T_1 F_17 ( struct V_1 * V_2 , T_1 V_22 , T_1 V_26 )
{
unsigned long V_23 ;
T_1 V_24 = 0 ;
F_12 ( & V_2 -> V_25 , V_23 ) ;
if ( F_2 ( & V_2 -> V_4 ) )
V_24 = F_18 ( & V_2 -> V_4 , V_22 , V_26 ) ;
else if ( F_4 ( & V_2 -> V_5 ) )
V_24 = F_19 ( & V_2 -> V_5 , V_22 , V_26 ) ;
else
F_15 ( 1 ) ;
F_16 ( & V_2 -> V_25 , V_23 ) ;
return V_24 ;
}
T_1 F_20 ( struct V_1 * V_2 , T_1 V_22 , T_1 V_26 )
{
unsigned long V_23 ;
T_1 V_24 = 0 ;
F_12 ( & V_2 -> V_25 , V_23 ) ;
if ( F_2 ( & V_2 -> V_4 ) )
V_24 = F_21 ( & V_2 -> V_4 , V_22 , V_26 ) ;
else if ( F_4 ( & V_2 -> V_5 ) )
V_24 = F_22 ( & V_2 -> V_5 , V_22 , V_26 ) ;
else
F_15 ( 1 ) ;
F_16 ( & V_2 -> V_25 , V_23 ) ;
return V_24 ;
}
T_1 F_23 ( struct V_1 * V_2 , T_1 V_22 , T_1 V_26 )
{
unsigned long V_23 ;
T_1 V_24 = 0 ;
F_12 ( & V_2 -> V_25 , V_23 ) ;
if ( F_2 ( & V_2 -> V_4 ) )
V_24 = F_24 ( & V_2 -> V_4 , V_22 , V_26 ) ;
F_16 ( & V_2 -> V_25 , V_23 ) ;
return V_24 ;
}
T_1 F_25 ( struct V_1 * V_2 , T_1 V_22 , T_1 V_26 )
{
unsigned long V_23 ;
T_1 V_24 = 0 ;
F_12 ( & V_2 -> V_25 , V_23 ) ;
if ( F_2 ( & V_2 -> V_4 ) )
V_24 = F_26 ( & V_2 -> V_4 , V_22 , V_26 ) ;
else if ( F_4 ( & V_2 -> V_5 ) )
V_24 = F_27 ( & V_2 -> V_5 , V_22 , V_26 ) ;
else
F_15 ( 1 ) ;
F_16 ( & V_2 -> V_25 , V_23 ) ;
return V_24 ;
}
T_1 F_28 ( struct V_1 * V_2 , T_1 V_22 , T_1 V_26 )
{
unsigned long V_23 ;
T_1 V_24 = 0 ;
F_12 ( & V_2 -> V_25 , V_23 ) ;
if ( F_2 ( & V_2 -> V_4 ) )
V_24 = F_29 ( & V_2 -> V_4 , V_22 , V_26 ) ;
else if ( F_4 ( & V_2 -> V_5 ) )
V_24 = F_30 ( & V_2 -> V_5 , V_22 , V_26 ) ;
else
F_15 ( 1 ) ;
F_16 ( & V_2 -> V_25 , V_23 ) ;
return V_24 ;
}
static int F_31 ( struct V_1 * V_2 , unsigned long V_27 )
{
struct V_28 * V_10 = (struct V_28 * ) V_27 ;
struct V_29 * V_30 ;
unsigned int V_31 ;
int V_24 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_32 ; V_31 ++ ) {
V_30 = & ( V_2 -> V_33 [ V_31 ] ) ;
if ( V_30 -> V_34 . V_35 != V_36 )
continue;
if ( ! V_30 -> V_30 ||
! V_30 -> V_30 -> V_37 ||
! F_32 ( V_30 -> V_30 ) )
continue;
V_24 = F_33 ( V_30 , V_10 ) ;
if ( V_24 >= 0 )
return V_24 ;
}
return - V_6 ;
}
int F_34 ( struct V_28 * V_30 )
{
int V_38 ;
V_38 = F_35 ( V_30 ) ;
if ( ! V_38 )
return 0 ;
#ifdef F_36
V_38 = F_37 ( ( unsigned long ) V_30 , F_31 ) ;
if ( V_38 >= 0 )
return V_38 ;
#endif
return - V_6 ;
}
static int F_38 ( struct V_1 * V_2 , unsigned long V_27 )
{
const struct V_28 * V_10 = ( const struct V_28 * ) V_27 ;
struct V_29 * V_30 ;
unsigned int V_31 ;
int V_24 ;
for ( V_31 = 0 ; V_31 < V_2 -> V_32 ; V_31 ++ ) {
V_30 = & ( V_2 -> V_33 [ V_31 ] ) ;
if ( V_30 -> V_34 . V_35 != V_36 )
continue;
if ( ! V_30 -> V_30 ||
! V_30 -> V_30 -> V_37 ||
! F_32 ( V_30 -> V_30 ) )
continue;
V_24 = F_39 ( V_30 , V_10 ) ;
if ( V_24 >= 0 )
return V_24 ;
}
return - V_6 ;
}
int F_40 ( const struct V_28 * V_30 , T_2 V_39 , T_2 V_40 )
{
int V_24 ;
V_24 = F_41 ( V_30 , V_39 , V_40 ) ;
if ( V_24 >= 0 )
return V_24 ;
#ifdef F_36
V_24 = F_37 ( ( unsigned long ) V_30 , F_38 ) ;
if ( V_24 >= 0 )
return V_24 ;
#endif
return - V_6 ;
}
