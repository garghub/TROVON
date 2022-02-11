static void F_1 ( struct V_1 * V_1 )
{
#ifdef F_2
struct V_2 * V_3 , * V_4 , * V_5 ;
T_1 * V_6 , * V_7 , * V_8 ;
unsigned long V_9 ;
if ( F_3 ( & F_4 ( V_1 ) -> V_10 ) ) {
F_5 ( L_1 , V_1 -> V_11 ) ;
return;
}
F_5 ( L_2 , V_1 -> V_11 ) ;
F_6 ( & F_4 ( V_1 ) -> V_12 , V_9 ) ;
F_7 (io, &EXT4_I(inode)->i_completed_io_list, list) {
V_3 = & V_6 -> V_13 ;
V_4 = V_3 -> V_14 ;
V_7 = F_8 ( V_4 , T_1 , V_13 ) ;
V_5 = V_3 -> V_15 ;
V_8 = F_8 ( V_5 , T_1 , V_13 ) ;
F_5 ( L_3 ,
V_6 , V_1 -> V_11 , V_7 , V_8 ) ;
}
F_9 ( & F_4 ( V_1 ) -> V_12 , V_9 ) ;
#endif
}
extern int F_10 ( struct V_1 * V_1 )
{
T_1 * V_6 ;
struct V_16 * V_17 = F_4 ( V_1 ) ;
unsigned long V_9 ;
int V_18 = 0 ;
int V_19 = 0 ;
if ( F_3 ( & V_17 -> V_10 ) )
return V_18 ;
F_1 ( V_1 ) ;
F_6 ( & V_17 -> V_12 , V_9 ) ;
while ( ! F_3 ( & V_17 -> V_10 ) ) {
V_6 = F_11 ( V_17 -> V_10 . V_15 ,
T_1 , V_13 ) ;
F_9 ( & V_17 -> V_12 , V_9 ) ;
V_18 = F_12 ( V_6 ) ;
F_6 ( & V_17 -> V_12 , V_9 ) ;
if ( V_18 < 0 )
V_19 = V_18 ;
else
F_13 ( & V_6 -> V_13 ) ;
}
F_9 ( & V_17 -> V_12 , V_9 ) ;
return ( V_19 < 0 ) ? V_19 : 0 ;
}
static int F_14 ( struct V_1 * V_1 )
{
struct V_20 V_21 ;
struct V_22 * V_22 = NULL ;
struct V_1 * V_15 ;
int V_18 = 0 ;
if ( ! F_15 ( V_1 , V_23 ) )
return 0 ;
V_1 = F_16 ( V_1 ) ;
while ( F_15 ( V_1 , V_23 ) ) {
F_17 ( V_1 , V_23 ) ;
V_22 = NULL ;
F_18 ( & V_1 -> V_24 ) ;
if ( ! F_3 ( & V_1 -> V_25 ) ) {
V_22 = F_19 ( & V_1 -> V_25 ,
struct V_22 , V_26 ) ;
F_20 ( V_22 ) ;
}
F_21 ( & V_1 -> V_24 ) ;
if ( ! V_22 )
break;
V_15 = F_16 ( V_22 -> V_27 -> V_28 ) ;
F_22 ( V_22 ) ;
if ( ! V_15 )
break;
F_23 ( V_1 ) ;
V_1 = V_15 ;
V_18 = F_24 ( V_1 -> V_29 ) ;
if ( V_18 )
break;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . V_30 = V_31 ;
V_21 . V_32 = 0 ;
V_18 = F_25 ( V_1 , & V_21 ) ;
if ( V_18 )
break;
}
F_23 ( V_1 ) ;
return V_18 ;
}
static int F_26 ( struct V_1 * V_1 , int V_33 )
{
int V_34 ;
int V_18 ;
V_18 = F_24 ( V_1 -> V_29 ) ;
if ( ! ( V_1 -> V_35 & V_36 ) )
return V_18 ;
if ( V_33 && ! ( V_1 -> V_35 & V_37 ) )
return V_18 ;
V_34 = F_27 ( V_1 , 1 ) ;
if ( V_18 == 0 )
V_18 = V_34 ;
return V_18 ;
}
int F_28 ( struct V_38 * V_38 , T_2 V_39 , T_2 V_40 , int V_33 )
{
struct V_1 * V_1 = V_38 -> V_41 -> V_42 ;
struct V_16 * V_17 = F_4 ( V_1 ) ;
T_3 * V_43 = F_29 ( V_1 -> V_44 ) -> V_45 ;
int V_18 ;
T_4 V_46 ;
bool V_47 = false ;
F_30 ( F_31 () == NULL ) ;
F_32 ( V_38 , V_33 ) ;
V_18 = F_33 ( V_1 -> V_29 , V_39 , V_40 ) ;
if ( V_18 )
return V_18 ;
F_34 ( & V_1 -> V_48 ) ;
if ( V_1 -> V_44 -> V_49 & V_50 )
goto V_51;
V_18 = F_10 ( V_1 ) ;
if ( V_18 < 0 )
goto V_51;
if ( ! V_43 ) {
V_18 = F_26 ( V_1 , V_33 ) ;
if ( ! V_18 && ! F_3 ( & V_1 -> V_25 ) )
V_18 = F_14 ( V_1 ) ;
goto V_51;
}
if ( F_35 ( V_1 ) ) {
V_18 = F_36 ( V_1 -> V_44 ) ;
goto V_51;
}
V_46 = V_33 ? V_17 -> V_52 : V_17 -> V_53 ;
if ( V_43 -> V_54 & V_55 &&
! F_37 ( V_43 , V_46 ) )
V_47 = true ;
F_38 ( V_43 , V_46 ) ;
V_18 = F_39 ( V_43 , V_46 ) ;
if ( V_47 )
F_40 ( V_1 -> V_44 -> V_56 , V_57 , NULL ) ;
V_51:
F_41 ( & V_1 -> V_48 ) ;
F_42 ( V_1 , V_18 ) ;
return V_18 ;
}
