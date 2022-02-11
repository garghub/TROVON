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
int V_18 = 0 ;
while ( V_1 && F_15 ( V_1 , V_23 ) ) {
F_16 ( V_1 , V_23 ) ;
V_22 = F_11 ( V_1 -> V_24 . V_15 ,
struct V_22 , V_25 ) ;
if ( ! V_22 || ! V_22 -> V_26 || ! V_22 -> V_26 -> V_27 )
break;
V_1 = V_22 -> V_26 -> V_27 ;
V_18 = F_17 ( V_1 -> V_28 ) ;
if ( V_18 )
break;
memset ( & V_21 , 0 , sizeof( V_21 ) ) ;
V_21 . V_29 = V_30 ;
V_21 . V_31 = 0 ;
V_18 = F_18 ( V_1 , & V_21 ) ;
if ( V_18 )
break;
}
return V_18 ;
}
int F_19 ( struct V_32 * V_32 , int V_33 )
{
struct V_1 * V_1 = V_32 -> V_34 -> V_35 ;
struct V_16 * V_17 = F_4 ( V_1 ) ;
T_2 * V_36 = F_20 ( V_1 -> V_37 ) -> V_38 ;
int V_18 ;
T_3 V_39 ;
bool V_40 = false ;
F_21 ( F_22 () == NULL ) ;
F_23 ( V_32 , V_33 ) ;
if ( V_1 -> V_37 -> V_41 & V_42 )
return 0 ;
V_18 = F_10 ( V_1 ) ;
if ( V_18 < 0 )
goto V_43;
if ( ! V_36 ) {
V_18 = F_24 ( V_32 , V_33 ) ;
if ( ! V_18 && ! F_3 ( & V_1 -> V_24 ) )
V_18 = F_14 ( V_1 ) ;
goto V_43;
}
if ( F_25 ( V_1 ) ) {
V_18 = F_26 ( V_1 -> V_37 ) ;
goto V_43;
}
V_39 = V_33 ? V_17 -> V_44 : V_17 -> V_45 ;
if ( V_36 -> V_46 & V_47 &&
! F_27 ( V_36 , V_39 ) )
V_40 = true ;
F_28 ( V_36 , V_39 ) ;
V_18 = F_29 ( V_36 , V_39 ) ;
if ( V_40 )
F_30 ( V_1 -> V_37 -> V_48 , V_49 , NULL ) ;
V_43:
F_31 ( V_1 , V_18 ) ;
return V_18 ;
}
